

#include <iostream>
using namespace std;

// Define the structure of a tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function for preorder traversal
void preorderTraversal(Node *node) {
    if (node == nullptr)
        return;

    // Visit the root node
    cout << node->data << " ";
    // Traverse the left subtree
    preorderTraversal(node->left);
    // Traverse the right subtree
    preorderTraversal(node->right);
}

int main() {
    // Create nodes
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Preorder traversal of the binary tree: ";
    preorderTraversal(root);

    return 0;
}
