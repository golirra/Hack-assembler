
#include <stdio.h>
#include "binary.h"


void printBinary16(unsigned int num) {
    for (int i = 15; i >= 0; i--) {
        // Extract the i-th bit using a bitwise AND and shift
        unsigned int bit = (num >> i) & 1;
        printf("%u", bit);
    }
    printf("\n");
}
int main() {
     unsigned int number;
    // Get user input
    printf("Enter a number (0 to 65535): ");
    scanf("%u", &number);
    // Check for 16-bit range
    if (number > 65535) {
        printf("Error: Number exceeds 16-bit range.\n");
        return 1;
    }
    printf("16-bit binary: ");
    printBinary16(number);
    return 0; 
}
