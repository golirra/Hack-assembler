#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linked_list.h"
#include "binary.h"//takes in an int currently
#include "PredefinedSymbols.h"
/**
 * @brief Converts hack assembly to 16 bit binary
 *
 *
 */
int main() {
    FILE *file_ptr;
    unsigned int line_count = 1;
    char *dest;
    char *comp;
    char *jump;
    char instruction[17];
    unsigned int num;
    char a = '0';
    char *token;
    InstructField c_instruct_field;

    // Character buffer that stores the read character till the next iteration
    char buff[200];
    // open file in read mode
    file_ptr = fopen("assembly-examples.txt", "r");
    if (NULL == file_ptr) {
        printf("file can't be opened \n");
          return EXIT_FAILURE;
    }
    //Parse the file
    while(fgets(buff, sizeof(buff), file_ptr)) {
        //Skip comment lines
        if(strchr(buff, '/')){
            continue;
        }
        //A Instructions 
        if(strchr(buff, '@')){
            token = strtok(buff, " \t@");//strip unecessary chars from line
            num = atoi(token);
            //printf("%c",a_or_c_bit);
            printf("%s\n",strcat(&a, getBinary16(num)));//have to pass the address of "a" using &
            
            line_count++;
        }
        //C Instructions
        if(strchr(buff, '=')){
            strcat(instruction, "111");
            token = strtok(buff, " \t\n"); 
            dest = strtok(token, "=");//stuff before the '='
            comp = strtok(NULL, "=");//stuff after the '='
            strcat(instruction, getBinaryCode(comp,COMP));
            strcat(instruction, getBinaryCode(dest,DEST));
            strcat(instruction, "000");
            printf("%s", instruction);
            printf("\n");
            line_count++;
        }
        if(strchr(buff, ';')){
            strcat(instruction, "111");
            token = strtok(buff, " \t\n"); 
            comp = strtok(token, ";");
            jump = strtok(NULL, ";");
            strcat(instruction, getBinaryCode(comp,COMP));
            strcat(instruction, "000");
            strcat(instruction, getBinaryCode(jump,JUMP));
            printf("%s", instruction);
            printf("\n");
            line_count++;
        }
        if(strchr(buff, '(')){
            printf("%s", buff);
            line_count++;
        }
        token = NULL;//reset the instruction string
        memset(instruction, '\0', sizeof(instruction));
    }
    // close the file
    fclose(file_ptr);
    return 0;

}//end main


