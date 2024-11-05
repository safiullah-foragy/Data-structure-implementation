#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "element: " << ptr->data << "\n";
        ptr = ptr->next;
    }
}


 Node* insertAtFirst(Node *head, int data)
{
     Node *ptr;
     ptr = ( Node*)malloc(sizeof(Node));
    ptr->data = data; 

    ptr->next = head; 
    return ptr;
}
int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));

    // Link first and second nodes
    head->data = 10;
    head->next = second;

    // Link second and third nodes
    second->data = 20;
    second->next = third;

    // Link third and fourth nodes
    third->data = 30;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 40;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    int data = 50;
    head = insertAtFirst(head, data);

    int data2 = 55;
    head = insertAtFirst(head, data2);


    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}