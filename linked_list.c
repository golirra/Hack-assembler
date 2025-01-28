#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
/*linked list:
 * made of nodes, each node has a link to the next node in the list
 */
Node* create_node(const char* key, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->key = strdup(key);
    new_node->next = NULL;
    return new_node;
}

void insert(Node** head, const char* key, int value) {//double pointer to head??
    Node* new_node = create_node(key, value);
    if(!new_node) return;
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    Node* current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void display(Node* head) {
    Node* current = head;
    while(current) {
        printf("Key: %s, Value: %d\n", current->key, current->value);//%d/%s tells printf to expect an int/string
        current = current->next;
    }
}

void free_list(Node* head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp->key);  // Free the key string
        free(temp);       // Free the node
    }
}







