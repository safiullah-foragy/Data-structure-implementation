#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
     Node *next;
};

Node *linkedListTraversal(Node *ptr, int item)
{
    while (ptr != NULL)
    {
        if (item == ptr->data)
        {
            cout << "address for unsorted: " << ptr->next << "\n";
            return ptr;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return NULL;
}

Node *searchSorted(Node *ptr, int item)
{
    if (ptr == NULL)
    {
        cout << "List is empty!\n";
        return NULL;
    }
    // Node *temp = start;
    while (ptr != NULL)
    {
        if (ptr->data < item)
        {
            ptr = ptr->next;
        }

        else if (ptr->data == item)
        {
            cout << "address for sorted: " << ptr->next << "\n";
            return ptr; // if finds value
        }

        else
            return NULL; // 
    }
    return NULL; //if does not get value
}
int main()
{
    // node er naam declare
    Node *head;
     Node *second;
    Node *third;
    Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = ( Node *)malloc(sizeof(Node));
    second = ( Node *)malloc(sizeof(Node));
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

    int item = 20;

    auto searchedResult = linkedListTraversal(head, item);
    auto searchedSortedResult = searchSorted(head, item);

    if (searchedResult)
    {
        cout << "Found unsorted: " << searchedResult->data
             << endl;
    }
    else
    {
        cout << "Not found" << "\n";
    }

    if (searchedSortedResult)
    {
        cout << "Found sorted: " << searchedSortedResult->data << endl;
    }
    else
    {
        cout << "Not found" << "\n";
    }

    return 0;
}