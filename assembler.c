#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linked_list.h"
#include "binary.h"//takes in an int currently
typedef struct Symbol {
    char *name;//strings are going to be a pointer of chars
    int value;
} Symbol;

typedef struct SymbolTable {
    Symbol **symbols;//pointer of pointers, that way I can make an array out of it
    size_t count;
    size_t capacity;
} SymbolTable;
/* is this over designed?xd
typedef enum {
    STATE_NORMAL, //default
    STATE_COMMENT,
    STATE_SKIPLINE,
    STATE_WHITESPACE
} ParserState;
*/

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
    int line_count = 0;
    char instruction[16] = "";
    char dest[4];
    char comp[4];
    char jump[4];
    bool is_a_instruction = false;
    bool is_c_instruction = false;
    bool skip_line = false;
    bool whitespace = false;
    unsigned int num;
    SymbolTable table = {NULL, 0, 0};
    add_symbol(&table, "symbol1", 100);
    //printf("%s", table.symbols[0]->name);//symbol pointer print test>??
    char *token;
    char *at_pos;

    // Character buffer that stores the read character till the next iteration
    char buff[20];
    // open file in read mode
    file_ptr = fopen("assembly-examples.txt", "r");
    if (NULL == file_ptr) {
        printf("file can't be opened \n");
          return EXIT_FAILURE;
    }
    //Parse the file
    while(fgets(buff, sizeof(buff), file_ptr)) {
        //printf("%s", buff);//print raw line
        token = strtok(buff, "@");
        at_pos = strchr(buff, '@');
        if(at_pos != NULL) {//is an a instruction
            //strncat(instruction, at_pos, 1);
            instruction[0] = '0';
            num = atoi(token);
            printf("%s", instruction);
            printBinary16(num);
        }
        memset(instruction, '\0', sizeof(instruction));//reset the instruction string 
        //printf("%s", token);
    }
    // close the file
    fclose(file_ptr);
    return 0;

}//end main


