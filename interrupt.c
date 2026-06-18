#include <xc.h>

void delay();

void main(void) {
    TRISD = 0x00;  // PORTD as output (LEDs)
    TRISB = 0xFF;  // PORTB as input
    ADCON1 = 0x0F; // Configure all pins as digital
    GIE = 1;       // Enable global interrupts
    PEIE = 1;      // Enable peripheral interrupts
    INT0IE = 1;    // Enable external interrupt INT0

    return;
}

void __interrupt() isr(void) {
    while (INT0IF == 1) {
        LATD = 0xCC;
        delay();
        LATD = 0x33;
        delay();
        LATD = 0x00;
        INT0IF = 0; // Clear interrupt flag
    }
}

void delay() {
    int i, j;
    for (i = 0; i < 600; i++) {
        for (j = 0; j < 600; j++) {
        }
    }
}
