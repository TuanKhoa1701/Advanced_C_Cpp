#include <stdio.h>
#include <stdint.h>

#define Enable 1
#define Disable 0

typedef struct {
    uint8_t led1:1; // 1 bit for LED 1
    uint8_t led2:1; // 1 bit for LED 2
    uint8_t led3:1; // 1 bit for LED 3
    uint8_t led4:1; // 1 bit for LED 4
    uint8_t led5:1; // 1 bit for LED 5
    uint8_t led6:1; // 1 bit for LED 6
    uint8_t led7:1; // 1 bit for LED 7
    uint8_t led8:1; // 1 bit for LED 8
} LedControl;

void display_all_led(LedControl led){
    uint8_t *led_status = (uint8_t*) &led;
    for(int i=0; i < 8; i++){
        printf("LED %d: %d\n", i + 1, (*led_status >> i)&1 );
    }
}
int main() {
    LedControl led = {.led3 = Enable, .led4=Enable}; // Initialize all LEDs to OFF
    display_all_led(led);  
   
}