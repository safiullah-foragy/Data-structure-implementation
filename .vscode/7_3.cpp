

#include <iostream>
using namespace std;

// Define the structure of a tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function for inorder traversal
void postorderTraversal(Node *node) {
    if (node == NULL)
        return;

    // Traverse the left subtree
    postorderTraversal(node->left);

    
    
    // Traverse the right subtree
    postorderTraversal(node->right);

    // Visit the root node
    cout << node->data << " ";
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

    cout << "postorder traversal : ";
    postorderTraversal(root);

    return 0;
}
