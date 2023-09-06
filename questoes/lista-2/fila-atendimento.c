#include <stdlib.h>
#include <stdio.h>

#define MAX_QUEUE_SIZE 100

typedef struct Person Person;
struct Person
{
    int idade;
    int ID;
};

typedef struct queue queue;
struct queue
{
    Person *items[MAX_QUEUE_SIZE];
    int current_size;
    int head;
    int tail;
};

int is_empty(queue *queue)
{
    return (queue->current_size == 0);
}


queue* create_queue()
{
    queue *new_queue = (queue*) malloc(sizeof(queue));
    Person *person = malloc(sizeof *person);

    for(int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        new_queue->items[i] = person;
    }

    new_queue->current_size = 0;
    new_queue->head = 0;
    new_queue->tail = 0;

    return new_queue;
}

void enqueue(queue *queue, int ID, int idade)
{
    if (queue->current_size >= MAX_QUEUE_SIZE) 
    {
        printf("Queue overflow");
    } 
    else if(queue->current_size == 0)
    {
        Person *person = malloc(sizeof *person);
        person->ID = ID;
        person->idade = idade;

        queue->items[queue->tail] = person;

        queue->current_size++;
    }
    else 
    {
        Person *person = malloc(sizeof *person);
        person->ID = ID;
        person->idade = idade;

        queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;
        queue->items[queue->tail] = person;

        queue->current_size++;
    }
}

void dequeue(queue *queue)
{
    if (is_empty(queue)) 
    {
        printf("Queue underflow");
    } 
    else 
    {
        queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;
        queue->current_size--;
    }
}

void printQueue(queue *queue)
{
    if(queue->current_size == 0)
    {
        printf("Fila vazia!\n");
        return;
    }
    int i;
    for(i = 0; i < queue->current_size; i++)
    {
        printf("ID: %d IDADE: %d\n", queue->items[i]->ID, queue->items[i]->idade);
    }
}

void printInverseQueue(queue *queue)
{
    int i;
    for(i = queue->tail; i >= 0; i++)
    {
        printf("ID: %d IDADE: %d\n", queue->items[i]->ID, queue->items[i]->idade);
    }
}

int main(int argc, char *argv[])
{
    queue *Queue = create_queue();
    queue *oldQueue = create_queue();
    int n;
    char input;

    scanf("%d", &n);

    int idade, ID;
    int cont = 0;

    scanf("%c", &input);

    while(1){
        switch (input){
            case 'a':
                scanf("%d %d\n", &ID, &idade);

                if(idade >= 60){
                    enqueue(&old_queue, ID, idade);
                }else{
                    enqueue(&queue, ID, idade);
                }
                break;
            case 'r':
                if(cont < n){
                    dequeue(&old_queue);
                    cont++;
                }
                else
                {
                    dequeue(&queue);
                    cont = 0;
                }
                break;
            case 'i':
                print_filas(&queue, &old_queue);
                break;
            case 'f':
                return EXIT_SUCCESS;
        }
        scanf("%c", &input);
    }

    return EXIT_SUCCESS;
}

