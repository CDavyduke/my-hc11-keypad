/*
 * C include file for EE 308
 * Spring, 1998
 */

#ifndef __HC11_H
#define __HC11_H    1

/* base address of register block, change this if you relocate the register
 * block. This is from an A8. May need to be changed for other HC11 members
 * or if you relocate the IO base address.
 */

#define _IO_BASE    0x1000
#define PORTA   (*(unsigned char  *)(_IO_BASE + 0x00))
#define PIOC    (*(unsigned char  *)(_IO_BASE + 0x02))
#define PORTC   (*(unsigned char  *)(_IO_BASE + 0x03))
#define PORTB   (*(unsigned char  *)(_IO_BASE + 0x04))
#define PORTCL  (*(unsigned char  *)(_IO_BASE + 0x05))
#define DDRC    (*(unsigned char  *)(_IO_BASE + 0x07))
#define PORTD   (*(unsigned char  *)(_IO_BASE + 0x08))
#define DDRD    (*(unsigned char  *)(_IO_BASE + 0x09))
#define PORTE   (*(unsigned char  *)(_IO_BASE + 0x0A))
#define CFORC   (*(unsigned char  *)(_IO_BASE + 0x0B))
#define OC1M    (*(unsigned char  *)(_IO_BASE + 0x0C))
#define OC1D    (*(unsigned char  *)(_IO_BASE + 0x0D))
#define TCNT    (*(unsigned short *)(_IO_BASE + 0x0E))
#define TIC1    (*(unsigned short *)(_IO_BASE + 0x10))
#define TIC2    (*(unsigned short *)(_IO_BASE + 0x12))
#define TIC3    (*(unsigned short *)(_IO_BASE + 0x14))
#define TOC1    (*(unsigned short *)(_IO_BASE + 0x16))
#define TOC2    (*(unsigned short *)(_IO_BASE + 0x18))
#define TOC3    (*(unsigned short *)(_IO_BASE + 0x1A))
#define TOC4    (*(unsigned short *)(_IO_BASE + 0x1C))
#define TOC5    (*(unsigned short *)(_IO_BASE + 0x1E))
#define TCTL1   (*(unsigned char  *)(_IO_BASE + 0x20))
#define TCTL2   (*(unsigned char  *)(_IO_BASE + 0x21))
#define TMSK1   (*(unsigned char  *)(_IO_BASE + 0x22))
#define TFLG1   (*(unsigned char  *)(_IO_BASE + 0x23))
#define TMSK2   (*(unsigned char  *)(_IO_BASE + 0x24))
#define TFLG2   (*(unsigned char  *)(_IO_BASE + 0x25))
#define PACTL   (*(unsigned char  *)(_IO_BASE + 0x26))
#define PACNT   (*(unsigned char  *)(_IO_BASE + 0x27))
#define SPCR    (*(unsigned char  *)(_IO_BASE + 0x28))
#define SPSR    (*(unsigned char  *)(_IO_BASE + 0x29))
#define SPDR    (*(unsigned char  *)(_IO_BASE + 0x2A))
#define BAUD    (*(unsigned char  *)(_IO_BASE + 0x2B))
#define SCCR1   (*(unsigned char  *)(_IO_BASE + 0x2C))
#define SCCR2   (*(unsigned char  *)(_IO_BASE + 0x2D))
#define SCSR    (*(unsigned char  *)(_IO_BASE + 0x2E))
#define SCDR    (*(unsigned char  *)(_IO_BASE + 0x2F))
#define ADCTL   (*(unsigned char  *)(_IO_BASE + 0x30))
#define ADR1    (*(unsigned char  *)(_IO_BASE + 0x31))
#define ADR2    (*(unsigned char  *)(_IO_BASE + 0x32))
#define ADR3    (*(unsigned char  *)(_IO_BASE + 0x33))
#define ADR4    (*(unsigned char  *)(_IO_BASE + 0x34))
#define BPROT   (*(unsigned char  *)(_IO_BASE + 0x35))
#define EPROG   (*(unsigned char  *)(_IO_BASE + 0x36))
#define OPTION  (*(unsigned char  *)(_IO_BASE + 0x39))
#define COPRST  (*(unsigned char  *)(_IO_BASE + 0x3A))
#define PPROG   (*(unsigned char  *)(_IO_BASE + 0x3B))
#define HPRIO   (*(unsigned char  *)(_IO_BASE + 0x3C))
#define INIT    (*(unsigned char  *)(_IO_BASE + 0x3D))
#define TEST1   (*(unsigned char  *)(_IO_BASE + 0x3E))
#define CONFIG  (*(unsigned char  *)(_IO_BASE + 0x3F))

/* These are the locations of the interrupt vectors defined by BUFFALO.
 * For example, to use the SCI interrupt, do the following before
 * enabling interrupts:
 *      
 *      SCI_JMP = JMP_OP_CODE;
 *      SCI_VEC =  sci_isr;
 *
 * where sci_isr() is the SCI interupt service routine:
 *
 *      #pragma interrupt_handler sci_isr
 *      void sci_isr(void)
 *      {
 *          interrupt-handling code
 *      }
 */

#define JMP_OP_CODE 0x7E;

#define SCI_JMP     (* (unsigned char *) 0x00C4)
#define SCI_VEC     (* (void     (**)()) 0x00C5)
#define SPI_JMP     (* (unsigned char *) 0x00C7)
#define SPI_VEC     (* (void     (**)()) 0x00C8)
#define PAIE_JMP    (* (unsigned char *) 0x00CA)
#define PAIE_VEC    (* (void     (**)()) 0x00CB)
#define PAO_JMP     (* (unsigned char *) 0x00CD)
#define PAO_VEC     (* (void     (**)()) 0x00CE)
#define TOF_JMP     (* (unsigned char *) 0x00D0)
#define TOF_VEC     (* (void     (**)()) 0x00D1)
#define TOC5_JMP    (* (unsigned char *) 0x00D3)
#define TOC5_VEC    (* (void     (**)()) 0x00D4)
#define TOC4_JMP    (* (unsigned char *) 0x00D6)
#define TOC4_VEC    (* (void     (**)()) 0x00D7)
#define TOC3_JMP    (* (unsigned char *) 0x00D9)
#define TOC3_VEC    (* (void     (**)()) 0x00DA)
#define TOC2_JMP    (* (unsigned char *) 0x00DC)
#define TOC2_VEC    (* (void     (**)()) 0x00DD)
#define TOC1_JMP    (* (unsigned char *) 0x00DF)
#define TOC1_VEC    (* (void     (**)()) 0x00E0)
#define TIC3_JMP    (* (unsigned char *) 0x00E2)
#define TIC3_VEC    (* (void     (**)()) 0x00E3)
#define TIC2_JMP    (* (unsigned char *) 0x00E5)
#define TIC2_VEC    (* (void     (**)()) 0x00E6)
#define TIC1_JMP    (* (unsigned char *) 0x00E8)
#define TIC1_VEC    (* (void     (**)()) 0x00E9)
#define RTI_JMP     (* (unsigned char *) 0x00EB)
#define RTI_VEC     (* (void     (**)()) 0x00EC)
#define IRQ_JMP     (* (unsigned char *) 0x00EE)
#define IRQ_VEC     (* (void     (**)()) 0x00EF)
#define XIRQ_JMP    (* (unsigned char *) 0x00F1)
#define XIRQ_VEC    (* (void     (**)()) 0x00F2)
#define SWI_JMP     (* (unsigned char *) 0x00F4)
#define SWI_VEC     (* (void     (**)()) 0x00F5)
#define ILLOP_JMP   (* (unsigned char *) 0x00F7)
#define ILLOP_VEC   (* (void     (**)()) 0x00F8)
#define COP_JMP     (* (unsigned char *) 0x00FA)
#define COP_VEC     (* (void     (**)()) 0x00FB)
#define CLM_JMP     (* (unsigned char *) 0x00FD)
#define CLM_VEC     (* (void     (**)()) 0x00FE)

#define enable()    asm("   cli")
#define disable()   asm("   sei")

#endif
