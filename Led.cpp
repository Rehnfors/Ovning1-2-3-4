#include "Led.h"
#include <iostream>


Led_type::Led_type(LedColor_Type _color, LedState_Type _state, const Led_type &led){ // Konstruktor för LED-objektet
  
	this->color  = _color; // Sätter till kulören från anropet
	this->state  = _state; // Sätter till state från anropet

	RCC->AHB1ENR |= LED_PORT_CLOCK; // Aktiverar klocka för GPIO B, "led port clock"
	
	switch(led.color){ // Kollar vilken kulör det är på LED:en och agerar därefter
		 
		case RED:                                        // Om det är rött
			LED_PORT->MODER |= LED_RED_MODE_BIT;         // Aktiverar General purpose output mode på pin 7
		  if(led.state  == ON){                          // Om state är ON...
			   LED_PORT->ODR |= LED_RED_PIN;             // Aktiveras Read/write på pin 7
				std::cout << "The RED Led is set ON \n\r";       
			}
			else{                                        
			  LED_PORT->ODR &= ~LED_RED_PIN;             // Annars stängs read/write av (om state är off)
        std::cout << "The RED Led is set OFF \n\r";

			}
		break;
            
		case YELLOW:                                        // Om det är gult
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT;         // Aktiverar general output mode på pin 13
		  if(led.state  == ON){                             // Om state är ON...
			   LED_PORT->ODR |= LED_YELLOW_PIN;             // Aktiveras read/write på pin 13
				std::cout << "The YELLOW Led is set ON \n\r"; 
			}
			else{                                           
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;             // Annars stängs read/write av (om state är off)
        std::cout << "The YELLOW Led is set OFF \n\r";

			}
		break;
    
		case BLUE:                                          // Om det är blått
			LED_PORT->MODER |= LED_BLUE_MODE_BIT;           // Aktiveras general output mode på pin 15
		  if(led.state  == ON){                             // Om state är ON...
			   LED_PORT->ODR |= LED_BLUE_PIN;               // Aktiveras read/write på pin 15
				std::cout << "The BLUE Led is set ON \n\r"; 
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;               // Annars stängs read/write av (om state är off)
        std::cout << "The BLUE Led is set OFF \n\r";

			}
		break;
		
		case GREEN:                                         // Om det är grönt
			LED_PORT->MODER |= LED_GREEN_MODE_BIT;          // Aktiveras general output mode på pin 12
		  if(led.state  == ON){                             // Om state är ON...
			   LED_PORT->ODR |= LED_GREEN_PIN;              // Aktiveras read/write på pin 12
				std::cout << "The GREEN Led is set ON \n\r"; 
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;              // Annars stängs read/write av (om state är off)
        std::cout << "The GREEN Led is set OFF \n\r";

			}
		break;
	
	}
}


void Led_type::Led_setState(LedState_Type _state, const Led_type &led){

	 this->state =  _state; // Sätter state till önskat läge

	 /*
     Följande switch-sats kollar vilken kulör LED:en har, om state är ON Så aktiveras motsvarande pin,
     exakt likadant som sker i konstruktorn. Detta för att säkerställa funktion om man stänger av/på utanför
     konstruktorn.
     */
	
	switch(led.color){
		 
		case RED:                                           
			LED_PORT->MODER |=LED_RED_MODE_BIT;             
		  if(led.state  == ON){
			   LED_PORT->ODR |= LED_RED_PIN;
				std::cout << "The RED Led is set ON \n\r";
			}
			else{
			  LED_PORT->ODR &= ~LED_RED_PIN;
        std::cout << "The RED Led is set OFF \n\r";

			}
		break;
		
		case YELLOW:
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(led.state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
				std::cout << "The YELLOW Led is set ON \n\r";
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
        std::cout << "The YELLOW Led is set OFF \n\r";

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(led.state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
				std::cout << "The BLUE Led is set ON \n\r";
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
        std::cout << "The BLUE Led is set OFF \n\r";

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(led.state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
				std::cout << "The GREEN Led is set ON \n\r";
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
        std::cout << "The GREEN Led is set OFF \n\r";

			}
		break;
	
	}
}


LedState_Type Led_type::Led_getState(const Led_type &led){ // Hämtar state på objektet led

	switch(led.color){ //Kollar kulör på led
		
		case RED:
			   std::cout << "The RED Led is currently " << led.state << "\n \r"; // Om det är rött så printas detta
				 break;
		
	  case GREEN:
			   std::cout << "The GREEN Led is currently " << led.state << "\n \r"; // Om det är grönt så printas detta
				 break;
		case BLUE:
			   std::cout << "The BLUE Led is currently " << led.state << "\n \r"; // Om det är blått så printas detta
				 break;
		case YELLOW:
			   std::cout << "The YELLOW Led is currently " << led.state << "\n \r"; // ...
				 break;
		
		
	 }
  
	return state; // Returnerar state
}