
// ============================================================================
//														  Motorola 68HC11
//   Example Keypad and LCD display drivers
//
//   For use with the Axiom CME11 development board
//   Compiled with Imagecraft C Compiler
//
//	To execute under buffalo, type load t, upload the s19 file then type
//	go 2440.  This is the beginning of the main() function for this program
//  as compiled.  If you re-compile it, look in the .mp file to locate main().
//
// ============================================================================

#include "hc11.h"

#define LINE_1      0x80                // beginning position of LCD line 1
#define LINE_2      0xC0                // beginning position of LCD line 2
#define LINE_3      0x94                // beginning position of LCD line 3
#define LINE_4      0xD4                // beginning position of LCD line 4

#define DELAY1MS	73		// number of loops = 1ms

// I/O Port Addresses
#define LCD_CMD  *(unsigned char *)(_IO_BASE + 0xA5F0)
#define LCD_DAT  *(unsigned char *)(_IO_BASE + 0xA5F1)

// Function Prototypes
void InitKey();
char kbhit();
char getkey();
void LCD_Command(unsigned char cval);
void LCD_busy(void);
void cprint(char dval);
void LCDprint(char *sptr);
void delay100ms(unsigned int secs);
void delay1ms(unsigned int msecs);
char dosomething();

// Global Variables
unsigned char	NewKey, LastKey;	// global variables used by keypad
unsigned char	ColCnt, colnum, rownum, keybuf;

main(){
	DDRD = 0x3E;	// set keypad I/O data direction register

	NewKey = 0; 	// reset key variables
	LastKey = 0xFF;

	// Initialize the LCD
    LCD_Command(0x3C);                 // initialize command
    LCD_Command(0x0C);                 // display on, cursor off
    LCD_Command(0x06);
    LCD_Command(0x01);

    // Display Header Information on LCD
    LCD_Command(LINE_1);               // goto lcd line 1
    LCDprint("Keypad Test");
    LCD_Command(LINE_2);               // goto lcd line 2
    LCDprint("Press Keys");
    LCD_Command(LINE_3);               // goto lcd line 3

	// main loop .. endless
	for( ; ;){

		if(kbhit()){				// if new key pressed
			cprint(NewKey);			// display it
		}

	}
}


// Wait for the LCD busy pin to clear
void LCD_busy(){
    while ((LCD_CMD & 0x80)) ;
}

void LCD_Command(unsigned char cval){
//unsigned char cval;
    LCD_busy();                         // wait for busy to clear
    LCD_CMD = cval;                     // ouptut command
}

//* LCD Display Character
void cprint(char dval){
    LCD_busy();                         // wait for busy to clear
    LCD_DAT = dval;                     // ouptut data
}

// LCD Display String
void LCDprint(char *sptr){
	while( *sptr ){
		cprint(*sptr);
		++sptr;
	}
}

//  Busy wait loop to generate a delay multiple of 1ms
void delay1ms(unsigned int msecs) {
  unsigned int i,j;

  if (msecs > 0) {
     for (j=0; j<=msecs; j++)
        for (i=0; i<DELAY1MS; i++);
  }
  return;
}

//  Busy wait loop to generate a delay multiple of 100ms.
void delay100ms(unsigned int secs){
  unsigned int i,j;

  if (secs > 0) {
     for (j=0; j<=secs; j++)
        for (i=0; i<100; i++)	delay1ms(1);
  }
}


// returns 1 if a key is pressed.
// the key value/index is stored in the global variable NewKey.
char kbhit(){
	unsigned char KeyDATA[] =
	 {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};

	for(ColCnt = 0, colnum = 0x04; colnum < 0x40; ColCnt = ColCnt +4){
		PORTD = colnum;	// set column value
		dosomething();	// delay
		rownum = PORTE;	// get row value
		rownum = (rownum & 0x0f);	// mask all but rows
		if(rownum){	// if a row in this column is high
			if(rownum == 0x04) rownum = 3;
			if(rownum == 0x08) rownum = 4;	/* figure row number */
			rownum = rownum - 1;
			keybuf = ColCnt + rownum;	/* calculate key index */
			if(keybuf == LastKey)	return 0; /* ignore if same key pressed */
			LastKey = keybuf;	/* save this key for repeat */
			NewKey = KeyDATA[keybuf];
			return 1;			/* return YES  */
		}
		colnum = colnum << 1;	// shift column left
	}
	LastKey = 0xff;	/* initialize key repeat compare value*/
	return 0;	/* no key pressed, return 0 */
}

char dosomething(){
	return 0;
}
// waits for a key press and returns it
char getkey(){
	while( !kbhit()){		// wait for key press
		dosomething();
	}
	return(NewKey);
}
