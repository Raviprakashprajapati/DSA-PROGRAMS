
// <aside>
// 💡 **Question 4**

// You need to construct a binary tree from a string consisting of parenthesis and integers.

// The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.
// You always start to construct the **left** child node of the parent first if it exists.

// **Input:** s = "4(2(3)(1))(6(5))"

// **Output:** [4,2,6,3,1,5]
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node *left;
  struct Node *right;
};

struct Node *construct_tree(char *s) {
  if (*s == '(') {
    // This is the start of a subtree.
    int val = atoi(s + 1);
    struct Node *node = malloc(sizeof(struct Node));
    node->val = val;
    node->left = construct_tree(s + (val + 1));
    node->right = construct_tree(s + (val + 2));
    return node;
  } else {
    // This is a leaf node.
    int val = atoi(s);
    struct Node *node = malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
  }
}

int main() {
  char *s = "4(2(3)(1))(6(5))";
  struct Node *root = construct_tree(s);
  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");
  return 0;
}

void inorder(struct Node *node) {
  if (node == NULL) {
    return;
  }
  inorder(node->left);
  printf("%d ", node->val);
  inorder(node->right);
}
