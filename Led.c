#include "led.h"


void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state){ // Konstruktor för LED-objektet
  
	me->color  = _color; // Sätter till kulören från anropet
	me->state  = _state; // Sätter till state från anropet

	RCC->AHB1ENR |= LED_PORT_CLOCK; // Aktiverar klocka för GPIO B, "led port clock"
	
	switch(_color){ // Kollar vilken kulör det är på LED:en och agerar därefter
		 
		case RED:                                        // Om det är rött
			LED_PORT->MODER |= LED_RED_MODE_BIT;         // Aktiverar General purpose output mode på pin 7
		  if(me->state  == ON){                          // Om state är ON...
			   LED_PORT->ODR |= LED_RED_PIN;             // Aktiveras Read/write på pin 7
				printf("The RED Led is set ON \n\r");       
			}
			else{                                        
			  LED_PORT->ODR &= ~LED_RED_PIN;             // Annars stängs read/write av (om state är off)
        printf("The RED Led is set OFF \n\r");

			}
		break;
            
		case YELLOW:                                        // Om det är gult
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT;         // Aktiverar general output mode på pin 13
		  if(me->state  == ON){                             // Om state är ON...
			   LED_PORT->ODR |= LED_YELLOW_PIN;             // Aktiveras read/write på pin 13
				printf("The YELLOW Led is set ON \n\r");
			}
			else{                                           
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;             // Annars stängs read/write av (om state är off)
        printf("The YELLOW Led is set OFF \n\r");

			}
		break;
    
		case BLUE:                                          // Om det är blått
			LED_PORT->MODER |= LED_BLUE_MODE_BIT;           // Aktiveras general output mode på pin 15
		  if(me->state  == ON){                             // Om state är ON...
			   LED_PORT->ODR |= LED_BLUE_PIN;               // Aktiveras read/write på pin 15
				printf("The BLUE Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;               // Annars stängs read/write av (om state är off)
        printf("The BLUE Led is set OFF \n\r");

			}
		break;
		
		case GREEN:                                         // Om det är grönt
			LED_PORT->MODER |= LED_GREEN_MODE_BIT;          // Aktiveras general output mode på pin 12
		  if(me->state  == ON){                             // Om state är ON...
			   LED_PORT->ODR |= LED_GREEN_PIN;              // Aktiveras read/write på pin 12
				printf("The GREEN Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;              // Annars stängs read/write av (om state är off)
        printf("The GREEN Led is set OFF \n\r");

			}
		break;
	
	}
}


void Led_setState(Led_Type * const me, LedState_Type _state){

	 me->state =  _state; // Sätter state till önskat läge

	 /*
     Följande switch-sats kollar vilken kulör LED:en har, om state är ON Så aktiveras motsvarande pin,
     exakt likadant som sker i konstruktorn. Detta för att säkerställa funktion om man stänger av/på utanför
     konstruktorn.
     */
	
	switch(me->color){
		 
		case RED:                                           
			LED_PORT->MODER |=LED_RED_MODE_BIT;             
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_RED_PIN;
				printf("The RED Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_RED_PIN;
        printf("The RED Led is set OFF \n\r");

			}
		break;
		
		case YELLOW:
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_YELLOW_PIN;
				printf("The YELLOW Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_YELLOW_PIN;
        printf("The YELLOW Led is set OFF \n\r");

			}
		break;
		
		case BLUE:
			LED_PORT->MODER |=LED_BLUE_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_BLUE_PIN;
				printf("The BLUE Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_BLUE_PIN;
        printf("The BLUE Led is set OFF \n\r");

			}
		break;
		
		case GREEN:
			LED_PORT->MODER |=LED_GREEN_MODE_BIT;
		  if(me->state  == ON){
			   LED_PORT->ODR |= LED_GREEN_PIN;
				printf("The GREEN Led is set ON \n\r");
			}
			else{
			  LED_PORT->ODR &= ~LED_GREEN_PIN;
        printf("The GREEN Led is set OFF \n\r");

			}
		break;
	
	}
}


LedState_Type Led_getState(Led_Type * const me){ // Hämtar state på medlemmen me i structen led_type

	switch(me->color){ //Kollar kulör på medlemmen me
		
		case RED:
			   printf("The RED Led is cureently %d \n\r",me->state); // Om det är rött så printas detta
				 break;
		
	  case GREEN:
			   printf("The GREEN Led is cureently %d \n\r",me->state); // Om det är grönt så printas detta
				 break;
		case BLUE:
			   printf("The BLUE Led is cureently %d\n\r",me->state); // Om det är blått så printas detta
				 break;
		case YELLOW:
			   printf("The YELLOW Led is cureently  %d \n\r",me->state); // ...
				 break;
		
		
	 }
  
	return me->state; // Returnerar state
}