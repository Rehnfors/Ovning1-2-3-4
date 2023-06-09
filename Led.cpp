#include "Led.h"
#include "PowerLed.h"
#include <iostream>
#include <thread>

Led_type::Led_type(LedState_Type _state)
{ // Konstruktor för LED-objektet

	this->state = _state

	RCC->AHB1ENR |= LED_PORT_CLOCK; // Aktiverar klocka för GPIO B, "led port clock"

	if (state == ON)
	{
		LED_PORT->MODER |= LED_RED_MODE_BIT; // Aktiverar General purpose output mode på pin 7
		LED_PORT->ODR |= LED_RED_PIN;		 // Aktiveras Read/write på pin 7
		std::cout << "The RED Led is set ON \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000));

		LED_PORT->MODER |= LED_YELLOW_MODE_BIT; // Aktiverar general output mode på pin 13
		LED_PORT->ODR |= LED_YELLOW_PIN;		// Aktiveras read/write på pin 13
		std::cout << "The YELLOW Led is set ON \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000));

		LED_PORT->MODER |= LED_BLUE_MODE_BIT; // Aktiveras general output mode på pin 15
		LED_PORT->ODR |= LED_BLUE_PIN;		  // Aktiveras read/write på pin 15
		std::cout << "The BLUE Led is set ON \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000));

		LED_PORT->MODER |= LED_GREEN_MODE_BIT; // Aktiveras general output mode på pin 12
		LED_PORT->ODR |= LED_GREEN_PIN;		   // Aktiveras read/write på pin 12
		std::cout << "The GREEN Led is set ON \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000));
	}

	else // Lägger till detta just bara för att det ska säkerställas att dessa är OFF.
	{
		LED_PORT->ODR &= ~LED_RED_PIN; 								 // Stänger av read/write på pin 7
		std::cout << "The RED Led is set OFF \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000)); // Avvakta 1 sekund

		LED_PORT->ODR &= ~LED_YELLOW_PIN; 							 // Stänger av read/write på pin 13
		std::cout << "The YELLOW Led is set OFF \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000)); // Avvakta 1 sekund

		LED_PORT->ODR &= ~LED_BLUE_PIN; 							 // Stänger av read/write på pin 15
		std::cout << "The BLUE Led is set OFF \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000)); // Avvakta 1 sekund

		LED_PORT->ODR &= ~LED_GREEN_PIN;							 // Stänger av read/write på pin 12
		std::cout << "The GREEN Led is set OFF \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000)); // Avvakta 1 sekund

		LED_PORT->MODER &= ~(LED_RED_MODE_BIT | LED_YELLOW_MODE_BIT | LED_BLUE_MODE_BIT | LED_GREEN_MODE_BIT); // Sätter tillbaka pinsen i default läge.
	}
}

void Led_type::Led_setState(LedState_Type _state, const Led_type &led)
{

	this->state = _state; // Sätter state till önskat läge

	if (state == ON)
	{
		LED_PORT->MODER |= LED_RED_MODE_BIT; // Aktiverar General purpose output mode på pin 7
		LED_PORT->ODR |= LED_RED_PIN;		 // Aktiveras Read/write på pin 7
		std::cout << "The RED Led is set ON \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000));

		LED_PORT->MODER |= LED_YELLOW_MODE_BIT; // Aktiverar general output mode på pin 13
		LED_PORT->ODR |= LED_YELLOW_PIN;		// Aktiveras read/write på pin 13
		std::cout << "The YELLOW Led is set ON \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000));

		LED_PORT->MODER |= LED_BLUE_MODE_BIT; // Aktiveras general output mode på pin 15
		LED_PORT->ODR |= LED_BLUE_PIN;		  // Aktiveras read/write på pin 15
		std::cout << "The BLUE Led is set ON \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000));

		LED_PORT->MODER |= LED_GREEN_MODE_BIT; // Aktiveras general output mode på pin 12
		LED_PORT->ODR |= LED_GREEN_PIN;		   // Aktiveras read/write på pin 12
		std::cout << "The GREEN Led is set ON \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000));
	}

	else
	{
		LED_PORT->ODR &= ~LED_RED_PIN; 								 // Stänger av read/write på pin 7
		std::cout << "The RED Led is set OFF \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000)); // Avvakta 1 sekund

		LED_PORT->ODR &= ~LED_YELLOW_PIN; 							 // Stänger av read/write på pin 13
		std::cout << "The YELLOW Led is set OFF \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000)); // Avvakta 1 sekund

		LED_PORT->ODR &= ~LED_BLUE_PIN; 						 	 // Stänger av read/write på pin 15
		std::cout << "The BLUE Led is set OFF \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000)); // Avvakta 1 sekund

		LED_PORT->ODR &= ~LED_GREEN_PIN; 							 // Stänger av read/write på pin 12
		std::cout << "The GREEN Led is set OFF \n\r";
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000)); // Avvakta 1 sekund

		LED_PORT->MODER &= ~(LED_RED_MODE_BIT | LED_YELLOW_MODE_BIT | LED_BLUE_MODE_BIT | LED_GREEN_MODE_BIT); // Sätter tillbaka pinsen i default läge
	}
}

LedState_Type Led_type::Led_getState(const Led_type &led) // Hämtar state på objektet led
{
	return state; // Returnerar state
}