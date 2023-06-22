#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* root, int value);
    bool search(int searchKey);
};

Node* BST::insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (value >= root->data) {
        root->right = insert(root->right, value);
    } else {
        root->left = insert(root->left, value);
    }

    return root;
}

bool BST::search(int searchKey) {
    Node* temp = root;
    while (temp != NULL) {
        if (temp->data == searchKey) {
            return true;
        } else if (temp->data > searchKey) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    return false;
}

int main() {
    BST tree;
    string ch = "yes";
    int num, searchKey;

    cout << "Enter the key number:\n";
    cin >> num;
    tree.root = tree.insert(tree.root, num);

    do {
        cout << "Do you want to create another junction?\n";
        cin >> ch;
        if (ch == "yes") {
            cout << "Enter the key number:\n";
            cin >> num;
            tree.root = tree.insert(tree.root, num);
        } else {
            break;
        }
    } while (true);

    cout << "\nEnter the key to be searched: ";
    cin >> searchKey;

    bool found = tree.search(searchKey);
    if (found) {
        cout << "\n" << searchKey << " found";
    } else {
        cout << "\n" << searchKey << " not found";
    }

    return 0;
}
