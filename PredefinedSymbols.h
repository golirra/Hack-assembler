#ifndef PREDEFINED_SYMBOLS_H
#define PREDEFINED_SYMBOLS_H
typedef enum {//enums in C are essentially ints that start from 0
    COMP,//0
    DEST,//1
    JUMP //2
}InstructField;
const char* getBinaryCode(const char *input, InstructField c_instruct_field);
#endif
