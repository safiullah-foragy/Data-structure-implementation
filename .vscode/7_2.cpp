

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

// Function for inorder traversal
void inorderTraversal(Node *node) {
    if (node == nullptr)
        return;

    // Traverse the left subtree
    inorderTraversal(node->left);

    
    // Visit the root node
    cout << node->data << " ";
    // Traverse the right subtree
    inorderTraversal(node->right);
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

    cout << "inorder traversal of the binary tree: ";
    inorderTraversal(root);

    return 0;
}
