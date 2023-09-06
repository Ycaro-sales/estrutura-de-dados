#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node 
{
    char data;
    struct Node* next;
};

int cat_list(Node* head, Node* head2){
    Node *curr = head;

    while (curr->next != NULL){
        curr = curr->next; 
    }
    curr->next = head2;

    return 1;
}

int main(int argc, char *argv[])
{
    printf("hello world\n");

    return EXIT_SUCCESS;
}
