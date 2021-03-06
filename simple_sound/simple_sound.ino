#include <CapSense.h>

#define LED1 PINF1 
#define LED2 PINF0 

void setup() {

    DDRF |= (1 << PINF1) | (1 << PINF0);
    DDRD = (1 << PIND0);
    timer_init();

}

void timer_init() {
    TCCR1B = (1 << CS12) | (1 << CS10);
    TIMSK1 = (1 << TOIE1);
    sei();
}


int i, j;
void loop() {
    for(j=1; j<10;j++) {
        for(i=0; i<255; i++) {
            PORTD ^= (1 << PIND0);        
            delayMicroseconds(i*j);
        }
    }
}

ISR(TIMER1_OVF_vect) {
    PORTF ^= (1 << PINF0) | (1 << PINF1);
}
