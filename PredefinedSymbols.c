#include <stdio.h>
#include <string.h>
#include "PredefinedSymbols.h"


/**
 *
 * This function returns a binary code based on parts of a "C" instruction.
 * 
 * @param *input The input string to check
 * @param c_instruct_field Decides which part of the instruction to convert
 * @return The binary code of the input
 */

const char* getBinaryCode(const char *input, InstructField c_instruct_field) {
    //comp field, a=0 (xxx0xxxxxxxxxxxx)
    if(c_instruct_field == COMP) {
        if (strcmp(input, "0") == 0) return "0101010";
        if (strcmp(input, "1") == 0) return "0111111";
        if (strcmp(input, "-1") == 0) return "0111010";
        if (strcmp(input, "D") == 0) return "0001100";
        if (strcmp(input, "A") == 0) return "0110000";
        if (strcmp(input, "!D") == 0) return "0001101";
        if (strcmp(input, "!A") == 0) return "0110001";
        if (strcmp(input, "-D") == 0) return "0001111";
        if (strcmp(input, "-A") == 0) return "0110011";
        if (strcmp(input, "D+1") == 0) return "0011111";
        if (strcmp(input, "A+1") == 0) return "0110111";
        if (strcmp(input, "D-1") == 0) return "0001110";
        if (strcmp(input, "A-1") == 0) return "0110010";
        if (strcmp(input, "D+A") == 0) return "0000010";
        if (strcmp(input, "D-A") == 0) return "0010011";
        if (strcmp(input, "A-D") == 0) return "0000111";
        if (strcmp(input, "D&A") == 0) return "0000000";
        if (strcmp(input, "D|A") == 0) return "0010101";
    //comp field, a=1 (xxx1xxxxxxxxxxxx)
        if (strcmp(input, "M") == 0) return "1110000";
        if (strcmp(input, "!M") == 0) return "1110001";
        if (strcmp(input, "-M") == 0) return "1110011";
        if (strcmp(input, "M+1") == 0) return "1110111";
        if (strcmp(input, "M-1") == 0) return "1110010";
        if (strcmp(input, "D+M") == 0) return "1000010";
        if (strcmp(input, "D-M") == 0) return "1010011";
        if (strcmp(input, "M-D") == 0) return "1000111";
        if (strcmp(input, "D&M") == 0) return "1000000";
        if (strcmp(input, "D|M") == 0) return "1010101";
    }
    //dest field
    if(c_instruct_field == DEST){
        if (strcmp(input, "M") == 0) return "001";
        if (strcmp(input, "D") == 0) return "010";
        if (strcmp(input, "MD") == 0) return "011";
        if (strcmp(input, "A") == 0) return "100";
        if (strcmp(input, "AM") == 0) return "101";
        if (strcmp(input, "AD") == 0) return "110";
        if (strcmp(input, "AMD") == 0) return "111";
    }
    //jump field
    if(c_instruct_field == JUMP) {
        if (strcmp(input, "JGT") == 0) return "001";
        if (strcmp(input, "JEQ") == 0) return "010";
        if (strcmp(input, "JGE") == 0) return "011";
        if (strcmp(input, "JLT") == 0) return "100";
        if (strcmp(input, "JNE") == 0) return "101";
        if (strcmp(input, "JLE") == 0) return "110";
        if (strcmp(input, "JMP") == 0) return "111";
    }
   return NULL;
}
