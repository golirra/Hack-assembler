#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int value;
    char* key;//should it be a pointer to the key?
    struct Node* next;
} Node;

Node* create_node(const char* key, int value);
void insert(Node** head, const char* key, int value);
void display(Node* head);
void free_list(Node* head);




#endif
