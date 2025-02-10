#include <stdio.h>
#include "binary.h"
#include <malloc.h>

char* getBinary16(unsigned int num) {
    char* binaryStr = (char*)malloc(17 * sizeof(char));//15 bit binary number + bit for null terminator
    if (binaryStr == NULL){
        fprintf(stderr, "memalloc failed\n");
        return NULL;

    }
    for (int i = 14; i >= 0; i--) {
        // Extract the i-th bit using a bitwise AND and shift
        unsigned int bit = (num >> i) & 1;
        binaryStr[14-i] = bit + '0';
    }
    binaryStr[17] ='\0';//null terminate the last bit
    return binaryStr;
}
/*
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
*/
