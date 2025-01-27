// C program to read a file using fgetc()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "binary.h"//takes in an int currently

int main() {
    // open file
    FILE *file_ptr;
    int line_count = 0;
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
        if(ch == '@')//has to be an a instruction 
             
        printf("%c", ch);
    }
    printf("%d", line_count);
    // close the file
    fclose(file_ptr);
    return 0;

}

