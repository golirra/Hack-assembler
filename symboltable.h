//#ifndef SYMBOLTABLE_H
//#define SYMBOLTABLE_H

/**
 * Populates a table with all the symbols one can encounter in the Hack assembly language
 *  predefined: R0-R15, SP[0], LCL[1], ARG[2], THIS[3], THAT[4], SCREEN[16384], KBD[24576]
 *  labels: (XXX) 
 *  variables: any symbol XXX that isn't predefined and is not defined elsewhere using (XXX) is a variable
 *
 */
/*
typedef struct Symbol {
    char* symbol;
    unsigned int value;
}Symbol;

typedef struct SymbolTable {
    Symbol** symbol_table;
}SymbolTable;
#endif
*/
