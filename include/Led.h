#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "uart.h"
#include "Led.h"
#include "stm32f4xx.h"

#define LED_PORT GPIOB

#define LED_PORT_CLOCK (1U << 1) // 0000 0000 0000 0010

#define LED_RED_PIN (1U << 14)    // 0100 0000 0000 0000
#define LED_GREEN_PIN (1U << 12)  // 0001 0000 0000 0000
#define LED_BLUE_PIN (1U << 15)   // 1000 0000 0000 0000
#define LED_YELLOW_PIN (1U << 13) // 0010 0000 0000 0000

#define LED_RED_MODE_BIT (1U << 28)    // 0001 0000 0000 0000 0000 0000 0000 0000
#define LED_GREEN_MODE_BIT (1U << 24)  // 0000 0001 0000 0000 0000 0000 0000 0000
#define LED_YELLOW_MODE_BIT (1U << 26) // 0000 0100 0000 0000 0000 0000 0000 0000
#define LED_BLUE_MODE_BIT (1U << 30)   // 0100 0000 0000 0000 0000 0000 0000 0000


typedef enum
{ // Gör enum för färger, dvs röd, grön, gul, blå istället för 0 1 2 3. Snyggare vid print

    RED = 0,
    GREEN,
    YELLOW,
    BLUE

} LedColor_Type;

typedef enum
{ // Liknande här, men OFF eller ON istället för 0 eller 1
    OFF = 0,
    ON = 1
} LedState_Type;


class Led_type
{
private:
public:
    LedState_Type state;
    Led_type(LedState_Type _state);                               // Konstruktor för LED-objektet
    void Led_setState(LedState_Type _state, const Led_type &led); // Sätter state, on eller off
    LedState_Type Led_getState(const Led_type &led);              // Tar emot state
};


#endif