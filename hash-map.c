typedef struct Node {
    char *symbol;
    int address;
    struct Node *next;
}Node;

Node *hashMap[100];//100 will have to be changed
