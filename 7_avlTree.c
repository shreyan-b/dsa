#include <stdio.h>
#include <stdlib.h>

struct AVL {
  int key;
  struct AVL *left;
  struct AVL *right;
  int height;
};

typedef struct AVL node;

int getHeight(node *n) {
  if (n == NULL) {
    return 0;
  }
  return n->height;
}

node *createNode(int key) {
  node *n = (node *)malloc(sizeof(node));
  n->key = key;
  n->left = NULL;
  n->right = NULL;
  n->height = 1;
  return n;
}

int max(int a, int b) { return (a > b) ? a : b; }

int getBalanceFactor(node *n) {
  if (n == NULL) {
    return 0;
  }
  return getHeight(n->left) - getHeight(n->right);
}

node *leftRotate(node *A) {
  node *B = A->left;
  node *RB = B->right;
  B->right = A;
  A->left = RB;
  A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
  B->height = max(getHeight(B->left), getHeight(B->right)) + 1;
  return B;
}

node *rightRotate(node *A) {
  node *B = A->right;
  node *LB = B->left;
  B->left = A;
  A->right = LB;
  A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
  B->height = max(getHeight(B->left), getHeight(B->right)) + 1;
  return B;
}

node *insert(node *n, int key) {
  int bf;
  if (n == NULL) {
    return createNode(key);
  }
  if (key < n->key) {
    n->left = insert(n->left, key);
  } else if (key > n->key) {
    n->right = insert(n->right, key);
  }
  n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
  bf = getBalanceFactor(n);
  if (bf > 1 && key < n->left->key) {
    return leftRotate(n);
  }
  if (bf < -1 && key > n->right->key) {
    return rightRotate(n);
  }
  if (bf > 1 && key > n->left->key) {
    n->left = rightRotate(n->left);
    return leftRotate(n);
  }
  if (bf < -1 && key < n->right->key) {
    n->right = leftRotate(n->right);
    return rightRotate(n);
  }
  return n;
}

void printtree(node *root, int space, int n) {
  int i;
  if (root == NULL) {
    return;
  }
  space = space + n;
  printtree(root->right, space, n);
  printf("\n");
  for (i = n; i < space; i++) {
    printf(" ");
  }
  printf("(%d)\n", root->key);
  printtree(root->left, space, n);
}

int main() {
  node *root = NULL;
  int n, i, key;
  printf("Enter the number of nodes\n");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter the key\n");
    scanf("%d", &key);
    root = insert(root, key);
  }
  printtree(root, 0, n);
  return 0;
}