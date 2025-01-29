//2025-01-27
//example of node struct for a linked list
typedef struct Node {
    int value;
    char* key;
    struct Node* next;
}Node;//gives a name to the typedef
int main() {
    Node node; //this is a variable of type Node
    Node* ptr; //this is a pointer to Node
    ptr = &node;//& is the "address-of" operator. so this assigns the address of 'node' to 'ptr.

    //lets use -> to access members via the pointer ptr
    ptr->value = 10;
    ptr->key = "example";
    //so in C we need -> to access the members of the struct, not the dot(.) operator
}
/*
 * can make pointer of pointers eg Symbol **symbols;
 */

char *token;
char str[10];
token = strtok(str, " \t\n");
//strtok can have multiple delimiter
//strtok can also grab before/ after the delimiter by calling strtok a second time and using NULL as the input string
