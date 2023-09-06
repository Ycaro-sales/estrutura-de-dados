#include <stdlib.h>
#include <stdio.h>

typedef struct binary_tree binary_tree ;

struct binary_tree{
    int item;
    binary_tree* left;
    binary_tree* right;
};

binary_tree* create_empty_binary_tree(){
    return NULL;
}

binary_tree* create_binary_tree(int data, binary_tree* left, binary_tree* right){
    binary_tree* new_node = malloc(sizeof *new_node);

    new_node->item = data;
    new_node->left = left;
    new_node->right = right;

    return new_node;
}

void create_binary_search_tree(binary_tree* parent, int data){
    if (data <= parent->item){
        if(parent->left == NULL)
            parent->left = create_binary_tree(data, NULL, NULL);
        else 
            create_binary_search_tree(parent->left, data);
    } else {
        if(parent->right == NULL)
            parent->right = create_binary_tree(data, NULL, NULL);
        else 
            create_binary_search_tree(parent->right, data);
    }
}


int is_empty(binary_tree* bt){
    if(bt->left || bt->right){
        return 1;
    }

    return 1;
}

void print_post_order(binary_tree *bt){
    if(!is_empty(bt)){
        print_post_order(bt->left);
        print_post_order(bt->right);
        printf("%d", bt->item);
    }
}

int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
