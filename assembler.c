// C program to read a file using fgetc()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linked_list.h"
#include "binary.h"//takes in an int currently

int main() {
    /*testing linked list include stuff
    Node* test = NULL;
    insert(&test, "ten",10);
    display(test);
    free_list(test);
    */
    FILE *file_ptr;
    int line_count = 0;
    char dest[50] = "";
    char instruction[50] = "";
    bool is_a_instruction = false;

    // Character buffer that stores the read character till the next iteration
    char ch;
    // open file in read mode
    file_ptr = fopen("assembly-test.txt", "r");
    if (NULL == file_ptr) {
        printf("file can't be opened \n");
          return EXIT_FAILURE;
    }
    // print file 
    while ((ch = fgetc(file_ptr)) != EOF) {
        if(ch == '\n') //increment linecount if character is a newline
            line_count = line_count + 1;
        if(ch == '@'){//has to be an a instruction 
            is_a_instruction = true;
            continue; //go to next iteration of while loop
            //strncat(dest, "0", 1);
        } 
        if(is_a_instruction) {
            if(ch == '\n'){
                is_a_instruction = false;
                break;
            } else {
                strncat(instruction, &ch, 1);
            }
        }


    }
    printf("Line count: %d\n", line_count);
    printf("Instruction: %s", instruction);
    // close the file
    fclose(file_ptr);
    return 0;

}

