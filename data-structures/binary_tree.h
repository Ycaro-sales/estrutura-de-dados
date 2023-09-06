#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binary_tree_node {
  void* data;
  struct binary_tree_node *left;
  struct binary_tree_node *right;
} binary_tree_node;

void binary_tree_insert(binary_tree_node **root, void* data);
void binary_tree_delete(binary_tree_node **root, void* data);
void binary_tree_print(binary_tree_node *root);
int binary_tree_size(binary_tree_node *root);
bool binary_tree_search(binary_tree_node *root, int chave);

#endif // !TREE_H
