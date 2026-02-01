#include <avr/io.h>
#include <util/delay.h>
#include "pins.h"

#define DT 500

void setup_out_pins() {
    DDRB |= D13;
    DDRD |= D2 | D3 | D4 | D5;
}

void pin_onoff(int pin, volatile uint8_t* port, bool on) {
    if (on) {
        *port |= pin;
    } else {
        *port &= ~pin;
    }
}

int main() {
    setup_out_pins();

    while (1) {
        pin_onoff(D13, &PORTB, 1); 
        _delay_ms(DT);

        pin_onoff(D13, &PORTB, 0); 
        _delay_ms(DT);
    }
}