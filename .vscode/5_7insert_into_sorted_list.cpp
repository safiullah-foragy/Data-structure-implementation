#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void linkedListTraversal(Node *ptr)
{
   
        while (ptr != NULL)
        {
            cout << "element: " << ptr->data <<endl;
            ptr = ptr->next;
        }
    
   
}

Node *insertSorted(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // Special case for the head end
    if (head == NULL || head->data >= data)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        // Locate the node before the point of insertion
        Node *current = head;
        while (current->next != NULL && current->next->data < data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
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

    int item = 245;


     printf("Linked list before insertion\n");
    linkedListTraversal(head);

    head = insertSorted(head, item);

    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);
    return 0;
}