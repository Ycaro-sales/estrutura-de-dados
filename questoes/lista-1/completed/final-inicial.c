#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node Node;

struct Node 
{
    char data;
    struct Node* next;
};

struct sequencia
{
    int index;
    int size;
};

void append(Node** head, char new_data)
{
    Node* new_node = malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next = NULL;

    Node* curr = *head;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new_node;
}

void evaluate(Node* head)
{
    Node* curr = head;

    struct sequencia maior_sequencia = {
        .index = 0,
        .size = 0
    };

    int curr_size = 0;
    int start_index = 0;
    int curr_index = 0;

    while(curr->next != NULL)
    {
        if (curr->data == '0')
        {
            curr_size += 1;
        } 
        else if(curr->next->data == '0') 
        {
            start_index = curr_index + 1;
        }

        if(curr->next->data == '1')
        {
            if(curr_size > maior_sequencia.size)
            {
                maior_sequencia.index = start_index;
                maior_sequencia.size = curr_size;
            }
            curr_size = 0;
        }

        curr = curr->next;
        curr_index += 1;
    }

    printf("%d %d\n", maior_sequencia.index, maior_sequencia.index + maior_sequencia.size - 1);
}

int main(int argc, char *argv[])
{
    while(1)
    {
        char string[100];
        scanf("%s", string);

        Node* head = NULL;

        for (int i = 0; i < strlen(string); i++){
            append(&head, string[i]);
        }

        if (head->data == '0' && head->next == NULL){
            break;
        }

        evaluate(head);
    }

    return 0;
}
