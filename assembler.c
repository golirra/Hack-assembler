#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linked_list.h"
#include "binary.h"//takes in an int currently
#include "PredefinedSymbols.h"
typedef struct Symbol {
    char *name;//strings are going to be a pointer of chars
    int value;
} Symbol;

typedef struct SymbolTable {
    Symbol **symbols;//pointer of pointers, that way I can make an array out of it
    size_t count;
    size_t capacity;
} SymbolTable;


void add_symbol (SymbolTable *table, const char *name, int value) {
    if (table->count == table->capacity) {
        // Increase capacity (e.g., double it)
        table->capacity = (table->capacity == 0) ? 1 : table->capacity * 2;
        table->symbols = realloc(table->symbols, table->capacity * sizeof(Symbol *));
        if (!table->symbols) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(1);
        }
    }
    Symbol *new_symbol = malloc(sizeof(Symbol));
    if(!new_symbol) {
        fprintf(stderr, "memalloc for new symbol failed\n");
        exit(1);
    }
    new_symbol->name = strdup(name);
    if(!new_symbol->name) {
        fprintf(stderr, "memalloc for symbol name failed\n");
        exit(1);
    }
    new_symbol->value = value;
    //add symbol the the array
    table->symbols[table->count] = new_symbol;
    table->count++;
}
int main() {
    FILE *file_ptr;
    unsigned int line_count = 1;
    char *dest;
    char *comp;
    char *jump;
    char instruction[17];
    bool is_a_instruction = false;
    bool is_c_instruction = false;
    bool skip_line = false;
    bool whitespace = false;
    unsigned int num;
    char *token;
    InstructField c_instruct_field;
    //SymbolTable table = {NULL, 0, 0};
    //add_symbol(&table, "symbol1", 100);
    //printf("%s", table.symbols[0]->name);//symbol pointer print test>??

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
            printf("A: ");
            printf("%s",getBinary16(num));
        }
        //C Instructions
        if(strchr(buff, '=')){
            printf(" C: ");
            strcat(instruction, "111");
            token = strtok(buff, " \t\n"); 
            dest = strtok(token, "=");//stuff before the '='
            comp = strtok(NULL, "=");//stuff after the '='
            strcat(instruction, getBinaryCode(comp,COMP));
            strcat(instruction, getBinaryCode(dest,DEST));
            strcat(instruction, "000");
            printf("%s", instruction);
            printf("\n");
        }
        if(strchr(buff, ';')){
            printf(" C: ");
            strcat(instruction, "111");
            token = strtok(buff, " \t\n"); 
            comp = strtok(token, ";");
            jump = strtok(NULL, ";");
            strcat(instruction, getBinaryCode(comp,COMP));
            strcat(instruction, "000");
            strcat(instruction, getBinaryCode(jump,JUMP));
            printf("%s", instruction);
            printf("\n");
        }
        if(strchr(buff, '(')){
            printf("%s", buff);
        }
        token = NULL;//reset the instruction string
        line_count = line_count + 1;
        memset(instruction, '\0', sizeof(instruction));
    }
    // close the file
    fclose(file_ptr);
    return 0;

}//end main


