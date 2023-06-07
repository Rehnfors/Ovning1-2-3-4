#include <stdio.h>

int main() {
    printf("Countdown:\n");
    
    for (int i = 10; i >= 0; i--) {
        printf("%d seconds remaining.\r", i);
        fflush(stdout);  // Ensure immediate output on some systems
        
        // Delay for 1 second (example purposes only)
        // replace with appropriate delay function in your code
        for (int j = 0; j < 100000000; j++) {}
    }
    
    printf("\n");
    
    return 0;
}
