#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Function to traverse and print the linked list
void linkedListTraversal(Node *ptr) {
    while (ptr != NULL) {
        cout << "Element: " << ptr->data << "\n";
        ptr = ptr->next;
    }
}

// Function to insert a new node after a given previous node
Node *insertAfterNode(Node *head, Node *prevNode, int data) {
    Node *ptr = new Node(); // Allocate new node
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

// Function to create a linked list from user input
Node *createLinkedList(int n) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data;

    for (int i = 0; i < n; i++) {
       
        cin >> data;
        newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    int n;
   
    cin >> n;

    Node *head = createLinkedList(n);

   
    linkedListTraversal(head);

    int data, position;
 
    cin >> data;
    
    cin >> position;

    Node *temp = head;
    for (int i = 1; i < position; i++) {
        if (temp->next == NULL) {
            cout << "Position exceeds list length. Aborting insert.\n";
            return 1;
        }
        temp = temp->next;
    }

    head = insertAfterNode(head, temp, data);

    cout << "\nLinked list after insertion:\n";
    linkedListTraversal(head);

    return 0;
}
