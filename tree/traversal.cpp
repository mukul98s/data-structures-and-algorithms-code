#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node (int val) {
      data = val;
      left = right = NULL;
    }
};

// left -> root -> right
void inOrder(Node* node) {
  if(node == NULL) return;

  inOrder(node->left);
  cout << node->data << " - ";
  inOrder(node->right);
}

// left -> right -> root
void postOrder(Node* node) {
  if(node == NULL) return;

  postOrder(node->left);
  postOrder(node->right);
  cout << node->data << " - ";
}

// root -> left -> right
void preOrder(Node* node) {
  if(node == NULL) return;

  cout << node->data << " - ";
  preOrder(node->left);
  preOrder(node->right);
}

int main() {
  Node* root = new Node(1);
  root->left = new Node(12);
  root->right = new Node(9);
  root->left->left = new Node(5);
  root->left->right = new Node(6);

  inOrder(root);
  preOrder(root);
  postOrder(root);

  return 0;
}