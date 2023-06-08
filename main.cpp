#include "uart.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	USART2_Init();

	std::cout << "Hello there from main function\n";

	while(1){}

	return 0;
}
