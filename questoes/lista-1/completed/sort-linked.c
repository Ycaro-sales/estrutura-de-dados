#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node{
    int data;
    Node* next;
};

Node* push(Node* head, char new_data)
{
    Node* new_node = malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next = head;

    return new_node;

}

int size_list(Node* head){
    Node* curr = head;
    int counter = 0;

    while (curr->next != NULL){
        counter += 1;
    }

    return counter;
}


void print_list(struct Node* head)
{
    Node* curr = head;
    
    if(curr == NULL){
        printf("Lista vazia\n");
        return;
    }

    while(curr-> next != NULL)
    {
        printf("%i ", curr->data);
        curr = curr->next;
    }
    printf("%i", curr->data);
}



void bubblesort_list(Node* head)
{
    Node *curr = head;
    int tmp;

    if(head->next->next == NULL){
        if(head->data < head->next->data){
            if (head->data > head->next->data) {
                int tmp = head->data;
                head->data = head->next->data;
                head->next->data = tmp;
                return;
            }
        }
    }

    for (Node *i = head->next; i->next != NULL; i = i->next){
        for (Node *j = head; j->next->next != NULL; j = j->next){
            if (j->data > j->next->data) {
                int tmp = j->data;
                j->data = j->next->data;
                j->next->data = tmp;

            }
        }
    }
}

int main(int argc, char *argv[])
{
    Node* head = NULL;
    int value;

	while (scanf("%d", &value) != EOF)
	{
		head = push(head, value);
	}


    bubblesort_list(head);

    print_list(head);

    return EXIT_SUCCESS;
}
