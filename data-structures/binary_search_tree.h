#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct binary_search_tree_node {
  int data;
  struct binary_search_tree_node *left;
  struct binary_search_tree_node *right;
} binary_search_tree_node;

void binary_search_tree_insert(binary_search_tree_node **root, int data);
void binary_search_tree_delete(binary_search_tree_node **root, int data);
void binary_search_tree_print(binary_search_tree_node *root);
int binary_search_tree_size(binary_search_tree_node *root);
bool binary_search_tree_search(binary_search_tree_node *root);

#endif // !BINARY_SEARCH_TREE_H
