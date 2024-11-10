#include <stdio.h>
#include <stdlib.h>

struct BST {
  int data;
  struct BST *left;
  struct BST *right;
};

typedef struct BST node;

void inorder(node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
  }
}

void preorder(node *root) {
  if (root != NULL) {
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
  }
}

node *insert(node *root, int key) {
  if (root == NULL) {
    root = (node *)malloc(sizeof(node));
    root->data = key;
    root->left = root->right = NULL;
    return root;
  }
  if (key < root->data) {
    root->left = insert(root->left, key);
  } else {
    root->right = insert(root->right, key);
  }
  return root;
}

void search(node *root, int key) {
  if (root == NULL) {
    printf("key is not found\n");
    return;
  }
  if (root->data == key) {
    printf("key is found\n");
    return;
  }
  if (key < root->data) {
    search(root->left, key);
  } else {
    search(root->right, key);
  }
}

int main() {
  int i, n, ch, key;
  node *root = NULL;
  printf("Enter the no of nodes: ");
  scanf("%d", &n);
  printf("Enter the elements: \n");
  for (i = 0; i < n; i++) {
    scanf("%d", &key);
    root = insert(root, key);
  }
  while (1) {
    printf("Enter choice:\n");
    printf("1-inorder, 2-preorder, 3-postorder, 4-search, 5-exit\n");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("Inorder is:\n");
      inorder(root);
      printf("\n");
      break;
    case 2:
      printf("Preorder is: \n");
      preorder(root);
      printf("\n");
      break;
    case 3:
      printf("Postorder is: \n");
      postorder(root);
      printf("\n");
      break;
    case 4:
      printf("Enter the element to be searched: ");
      scanf("%d", &key);
      search(root, key);
      break;
    default:
      printf("Invalid choice...\nexiting....\n\n");
      exit(0);
    }
  }
  return 0;
}
