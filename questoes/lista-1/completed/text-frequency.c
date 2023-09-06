#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node Node;

struct Node{
    char data;
    int frequency;
    Node* next;
};

void bubblesort(char* a, int size){
    for(int i = 0; i < size; i++){
        for(int j = 1; j < size-1; j++){
            if(a[i]>a[i+1]){
                char tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = a[i];
            }
        }
    }
}

Node* push(Node* head, char data, int frequency){
    Node* new_node = malloc(sizeof(Node));

    new_node->frequency = frequency;
    new_node->data = data;
    new_node->next = head;

    return new_node;
}

int main(int argc, char *argv[])
{
    char string[1000];

    scanf("%s", string);

    bubblesort(string, strlen(string));



    return EXIT_SUCCESS;
}
