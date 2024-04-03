#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the binary tree
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

// Function to create a new node
Node *newNode(int data) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

// Function to check if a character is a digit
int isDigit(char ch) { return ch >= '0' && ch <= '9'; }

// Recursive function to build the binary tree
Node *buildTree(char *str, int *index) {
  if (str[*index] == '(') {
    if (str[*index + 1] == ')') {
      *index += 2;
      return NULL;
    } else {
      *index += 1;
      int num = 0;
      int decimal = 0;
      while (isDigit(str[*index])) {
        num = num * 10 + (str[*index] - '0');
        *index += 1;
      }
      Node *root = newNode(num);
      root->left = buildTree(str, index);
      root->right = buildTree(str, index);
      *index += 1;
      return root;
    }
  } else {
    return NULL;
  }
}

// Function to print the inorder traversal of the tree
void preorder(Node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

int main() {
  char str[] = "(12(7(3()())(10()(11()())))(23(17()())(31()())))";
  int index = 0;
  Node *root = buildTree(str, &index);

  printf("preorder traversal of the tree: ");
  preorder(root);
  printf("\n");

  return 0;
}
