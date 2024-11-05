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
        cout  << ptr->data<<endl;
        ptr = ptr->next;
    }
}

 Node *deleteAtIndex(Node *head, int value)
{
   

    // If the head node itself holds the value to be deleted
    if (head->data == value)
    {
        Node *ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }

   Node *ptr = head;
    while (ptr->next != NULL && ptr->next->data != value)
    {
        ptr = ptr->next;
    }

    if (ptr->next != NULL && ptr->next->data == value)
    {
         Node *temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);
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
    head = ( Node *)malloc(sizeof( Node));
    second = ( Node *)malloc(sizeof(Node));
    third = ( Node *)malloc(sizeof( Node));
    fourth = ( Node *)malloc(sizeof( Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    int item = 4;
    head = deleteAtIndex(head, item);

    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}