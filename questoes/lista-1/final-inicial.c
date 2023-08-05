#include <stdlib.h>
#include <stdio.h>
#include "list.c"

struct sequencia{
  int index;
  int size;
};

void evaluate(struct node* head){
  struct node* curr = head;
  struct sequencia sequencia = {
    .index = 0,
    .size = 0
  };

  int tamanho = 0;
  int index = 0;

  while(curr->next != NULL){
    if (curr->data == 0){
      tamanho += 1;
    }

    if(curr->next->data == 1){
      if(tamanho > sequencia.size){
        sequencia.size = tamanho;
        sequencia.index = index;
      }
      tamanho = 0;
    }

    curr = curr->next;
    index += 1;
  }

  printf("%d %d", sequencia.index, sequencia.index + sequencia.size);
}

int main(int argc, char *argv[])
{
  return EXIT_SUCCESS;
}
