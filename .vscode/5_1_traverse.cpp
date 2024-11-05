#include<bits/stdc++.h>
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
        cout<<ptr->data<<"\n";
        ptr = ptr->next;
    }
}

int main()
{
    //node er naam declare
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;
    Node *fourth1;

    // Allocate memory for nodes in the linked list in Heap
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    fourth = (Node*)malloc(sizeof(Node));
    fourth1 = (Node*)malloc(sizeof(Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

     // Link  fourth and fifth nodes
    fourth->data = 66;
    fourth->next = fourth1;
    // Terminate the list at the  node
 fourth1->data = 667;
    fourth1->next = NULL;



    linkedListTraversal(head);
    return 0;
}
