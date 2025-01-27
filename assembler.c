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
    char instruction[16] = "";
    bool is_a_instruction = false;
    unsigned int num;

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
        if(ch == '@'){
            is_a_instruction = true;
            memset(instruction, '\0', sizeof(instruction));
            continue; //go to next iteration of while loop
        } 
        if(is_a_instruction) {
            if(ch == '\n'){
                num = atoi(instruction);//atoi doesnt handle errors? could be dangerous
                printf("%d",num);
                printBinary16(num);
                is_a_instruction = false;
                printf("Instruction: %s\n", instruction); 
                continue;
            } else {
                strncat(instruction, &ch, 1);
            }
        }
    }
    printf("Line count: %d\n", line_count);
    // close the file
    fclose(file_ptr);
    return 0;

}

