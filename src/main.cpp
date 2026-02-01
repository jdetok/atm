#include <avr/io.h>
#include <util/delay.h>

#define IO13 (1<< PB5)

int main() {
    DDRD |= IO13;

    while (1) {
        PORTB |= IO13;
        _delay_ms(500);

        PORTB &= ~IO13;
        _delay_ms(500);
    }
}