#include "uart.h"

void USART2_Init(void){ //Initiate USART2_I

 RCC->APB1ENR  |=  0x20000; //Ändrar bit 17 till 1, aktiverar klockan för USART2

 RCC->AHB1ENR   |=0x01; //Ändrar bit 0 till 1, aktiverar klockan för IO port A

 
GPIOA->MODER &= ~0x00F0; // Resettar pin 3, 4. Dvs bit 4, 5, 6, 7
GPIOA->MODER |= 0x00A0;  // Aktiverar alternativa funktionen för pin 3, 4.

 GPIOA->AFR[0] &= ~0xFF00; // Resettar pin 3 och 2
 GPIOA->AFR[0] |= 0x7700;  // Väljer Alternate function mode 7 till pin 3 och 2


USART2->BRR  =  0x0683;  // USARTDIV = 104.1875
USART2->CR1  =  0x000C;  // Aktiverar reciever och transmitter i control register 1
USART2->CR2  =  0x000;   // Sätter allting till 0 i CR2, dvs reset
USART2->CR3  =  0x000;   // Sätter allting till 0 i CR3, dvs reset.
USART2->CR1  |=  0x2000; // USART Enable 
	
	

}

int USART2_write(int ch){ // Initierar USART2_write, en int "ch" som argument för

	while(!(USART2->SR & 0x0080)){} // Kör så länge transmit data register inte är tomt
	USART2->DR = (ch & 0xFF);       // Sätter 1 på det som stämmer överens med ch,
                                    // bitwise AND för att säkerställa att det endast blir 8 bitar, som registret
	
  return ch; //returnera ch
}

int USART2_read(void){ // Initierar USART2_read
  while(!(USART2->SR & 0x0020)){} // Kör så länge inte Recieved data is ready to be read
	return USART2->DR;            // returnera sedan dataregistret.
}

struct __FILE { int handle; }; // Deklarerar en struct __FILE med en member, int handle
FILE __stdin  = {0};           // Initierar en instans av __FILE, __stdin med 0 som handle 
FILE __stdout = {1};           // Initierar en instans av __FILE, __stdout med 1 som handle 
FILE __stderr = {2};           // Initierar en instans av __FILE, __stderr med 2 som handle 


int fgetc(FILE *f) {     // Initierar funktionen fgetc, med en filpekare som argument
    int c;               // Deklarerar int c

    c = USART2_read();   // c = vad som läses från dataregistret   

    if (c == '\r') {      // letar efter carriage return-pekare      
        USART2_write(c);  // om den hittar pekaren, anropa USART_write med dess värde som argument
        c = '\n';         // c = ny rad
    }

    USART2_write(c);      // anropa USART2_write med c som argument  

    return c;             // returnerar c
}



int fputc(int c, FILE *f) { // Initierar fputc med en int "c" som argument, samt en filpekare
    return USART2_write(c);  // Returnerar värdet som lämnas av USART2_write med c som argument
}


int n;
char str[80];
		
void test_setup(void){
	
	printf("please enter a number: ");
	scanf("%d", &n);
	printf("the number entered is: %d\r\n", n);
	printf("please type a character string: ");
	gets(str);
	printf("the character string entered is: ");
	puts(str);
	printf("\r\n");
	
}