#include <string.h>
#include <stdio.h>


int main() {

char str[] = "D;JGT";
char *start;
char *end;
start = strtok(str, ";");
printf("%s", start);
start = strtok(NULL, ";"); 
printf("%s", start);




}
