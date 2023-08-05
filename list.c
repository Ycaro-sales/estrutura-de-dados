#include <stdlib.h>
#include <stdio.h>

struct node{
  int data;
  struct node* next;
};

void append(struct node* head, int new_data){
  struct node* new_node = malloc(sizeof(struct node));

  new_node->data = new_data;
  new_node->next = NULL;

  struct node* curr = head;

  while(curr->next != NULL){
    curr = curr->next;
  }

  curr->next = new_node;
}

void push(struct node* head, int new_data){
  struct node* new_node = malloc(sizeof(struct node));

  new_node-> data = head-> data;
  new_node-> next = head-> next;

  head-> data = new_data;
  head-> next = new_node;
}

void print_list(struct node* head){
  struct node* curr = head;

  while(curr-> next != NULL){
    printf("%i\n", curr-> data);
    curr = curr->next;
  }
}

void remove_node(struct node* head, int item){
  struct node* curr = head;
  struct node* removed = NULL;

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

void search(struct node *head, int item){
  struct node* curr = head;
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
