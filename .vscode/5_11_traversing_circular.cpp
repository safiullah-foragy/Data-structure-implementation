#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
     Node *next;
};

void linkedListTraversal( Node *head)
{
   

     Node *ptr = head;
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
     Node *head;
     Node *second;
    Node *third;
   Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = ( Node *)malloc(sizeof( Node));
    second = ( Node *)malloc(sizeof( Node));
    third = ( Node *)malloc(sizeof( Node));
    fourth = ( Node *)malloc(sizeof( Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;

    linkedListTraversal(head);

    return 0;
}