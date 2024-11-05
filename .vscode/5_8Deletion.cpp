#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void linkedListTraversal(Node *ptr) {
    while (ptr != NULL) {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

Node* deleteAtIndex(Node *head, int value) {
   

    // If the head node itself holds the value to be deleted
    if (head->data == value) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *ptr = head;
    while (ptr->next != nullptr && ptr->next->data != value) {
        ptr = ptr->next;
    }

    if (ptr->next != nullptr && ptr->next->data == value) {
        Node *temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }

    return head;
}

int main() {
    // Declare pointers for the linked list nodes
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = nullptr;

    cout << "Linked list before deletion\n";
    linkedListTraversal(head);

    int item = 4;
    head = deleteAtIndex(head, item);

    cout << "\nLinked list after deletion\n";
    linkedListTraversal(head);

    // Free memory for remaining nodes
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
