#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct Symbol {
    char* name;
    int value;
}Symbol;

typedef struct SymbolTable {
    Symbol **symbols;
    size_t count;
    size_t capacity;
}SymbolTable;

void init_symbol_table(SymbolTable *table) {
    table->count = 0;
    table->capacity = 2;  // Start with space for 2 symbols
    table->symbols = malloc(table->capacity * sizeof(Symbol *));
    if (!table->symbols) {
        perror("Failed to allocate symbol table");
        exit(1);
    }
}
void add_symbol(SymbolTable *table, const char *name, int value){
    if(table->count >= table->capacity) {
        table->capacity *= 2; //double table size
        //reallocate memory for the symbols, original object gets freed
        table->symbols = realloc(table->symbols, table->capacity * sizeof(Symbol *));
        if (!table->symbols) {
            perror("failed to resize symbol table");
            exit(1);
        }
    }
    //allocate memory for a new symbol
    Symbol *newSymbol = malloc(sizeof(Symbol));
    //always check if it worked
    if(!newSymbol) {
        perror("failed to allocate symbol");
        exit(1);
    }
    //have to allocate memory for char* name
    newSymbol->name = malloc(strlen(name) +1);
    if (!newSymbol->name) {
        perror("Failed to allocate memory for symbol name");
        free(newSymbol);  // Don't forget to free previously allocated memory
        exit(1);
    }
    //strcpy(*dest, *src);
    strcpy(newSymbol->name, name);
    newSymbol->value = value;
    //table->count is the current num of symbols stored in the table. 
    //so add the symbol to the table, and increment the count to point to the next position in the table
    table->symbols[table->count++] = newSymbol;
}
void add_predefined_symbols(SymbolTable *table) {

    const char *predefinedNames[] = {
        "R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8",
        "R9", "R10", "R11", "R12", "R13", "R14", "R15"
    };
    int predefinedValues[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14, 15
    };
}

void print_symbol_table(const SymbolTable *table) {
    for (size_t i = 0; i < table->count; ++i) {
        printf("Symbol: %s, Value: %d\n", table->symbols[i]->name, table->symbols[i]->value);
    }
}
void free_symbol_table(SymbolTable *table) {
    for (size_t i = 0; i < table->count; ++i) {
        free(table->symbols[i]);  // Free each Symbol
    }
    free(table->symbols);  // Free the array of pointers
}
int main() {



    SymbolTable table;

    init_symbol_table(&table);

    add_symbol(&table, "alpha", 10);
    add_symbol(&table, "beta", 20);
    add_symbol(&table, "gamma", 30);

    print_symbol_table(&table);

    free_symbol_table(&table);



}
