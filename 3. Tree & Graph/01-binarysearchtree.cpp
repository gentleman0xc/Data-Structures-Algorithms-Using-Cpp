#include <iostream>
using namespace std;

class Node {
public:
  int key;
  Node *left, *right;

  Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
  if (root == nullptr) {
    return new Node(key);
  } else if (key < root->key) {
    root->left = insert(root->left, key);
  } else {
    root->right = insert(root->right, key);
  }
  return root;
}

bool search(Node* root, int key) {
  if (root == nullptr) {
    return false;
  } else if (root->key == key) {
    return true;
  } else if (key < root->key) {
    return search(root->left, key);
  } else {
    return search(root->right, key);
  }
}

void inorder(Node* root) {
  if (root == nullptr) {
    return;
  }
  inorder(root->left);
  cout << root->key << " ";
  inorder(root->right);
}

void preorder(Node* root) {
  if (root == nullptr) {
    return;
  }
  cout << root->key << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node* root) {
  if (root == nullptr) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->key << " ";
}

int main() {
  Node* root = nullptr;
  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 2);
  root = insert(root, 7);
  root = insert(root, 12);
  root = insert(root, 17);

  cout << "Inorder traversal: ";
  inorder(root);
  cout << endl;

  cout << "Preorder traversal: ";
  preorder(root);
  cout << endl;

  cout << "Postorder traversal: ";
  postorder(root);
  cout << endl;

  int key;
  cout << "Enter a key to search: ";
  cin >> key;

  if (search(root, key)) {
    cout << "The key " << key << " was found." << endl;
  } else {
    cout << "The key " << key << " was not found." << endl;
  }

  return 0;
}
