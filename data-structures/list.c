#include <stdlib.h>
#include <stdio.h>

struct Node{
  int data;
  struct Node* next;
};

void append(struct Node* head, int new_data){
  struct Node* new_node = malloc(sizeof(struct Node));

  new_node->data = new_data;
  new_node->next = NULL;

  struct Node* curr = head;

  while(curr->next != NULL){
    curr = curr->next;
  }

  curr->next = new_node;
}

void push(struct Node* head, int new_data){
  struct Node* new_node = malloc(sizeof(struct Node));

  new_node-> data = head-> data;
  new_node-> next = head-> next;

  head-> data = new_data;
  head-> next = new_node;
}

void print_list(struct Node* head){
  struct Node* curr = head;

  while(curr-> next != NULL){
    printf("%i\n", curr-> data);
    curr = curr->next;
  }
}

void remove_node(struct Node* head, int item){
  struct Node* curr = head;
  struct Node* removed = NULL;

  while (curr->next != NULL){
    if (curr->next->data == item){
      removed = curr->next;
      curr->next = curr->next->next;
      free(removed);
      return;
    }
  }

  free(removed);
  printf("item not found");

  return;
}

void search(struct Node *head, int item){
  struct Node* curr = head;
  while (curr != NULL){
    if(curr->data == item){
      printf("a lista contem o item.");
      return;
    }
    curr = curr->next;
  }
  printf("A lista a lista nao contem o item.");
  return;
}
