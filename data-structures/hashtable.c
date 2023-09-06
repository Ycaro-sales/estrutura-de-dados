#include <c++/13.2.1/bits/fs_path.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "binary_search_tree.h"

#define MAX_SIZE 1000000

typedef struct hashtable {
    int size;
    binary_search_tree_node* vector [MAX_SIZE];
}Hashtable;

int hash(char* key, int size)
{
    return (int)key[0] % size;
}

void add(Hashtable* table, char* key){
    int index = hash(key, table->size);
    create
    
    if(table->vector[index] == NULL){
        table->vector[index] = new_node;
    }else{
    }
}
