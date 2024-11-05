#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
     Node *next;
};

linkedListTraversal(Node *ptr, int item)
{
    int count=1;
    
    while (ptr != NULL)
    {
       
        if (ptr->data == item)
        {
            return count; // returns pointer if finds
        }

        ptr=ptr->next;
       count++;
    }
    return -1;
   
}

int main()
{
    // Declare node names
  Node *head;
   Node *second;
    Node *third;
    Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = ( Node *)malloc(sizeof( Node));
    second = ( Node *)malloc(sizeof(Node));
    third = ( Node *)malloc(sizeof( Node));
    fourth = ( Node *)malloc(sizeof(Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes 
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    int item ;
    cin>>item;

    int result = linkedListTraversal(head, item);
if(result==-1){cout<<"not found"<<endl;}

else{

    cout<<"found at:"<<result<<endl;
}
    
    return 0;
}