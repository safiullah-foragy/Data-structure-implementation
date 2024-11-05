#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
     Node *next;
};

int traversal(Node *ptr,int item)
{

     int count=1;
    while (ptr != NULL)
    {

       
        if (item == ptr->data)
        {
            
            return count;
        }

        else if(item < ptr->data){return -1;}
        else
        {
            ptr = ptr->next;
        }
        count++;
    }
    return NULL;
}



int main()
{

    int item;
    cin>>item;
    // declaration of node
    Node *head;
   Node *second;
   Node *third;
    Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = ( Node *)malloc(sizeof(Node));
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

  
int ans=traversal(head,item);
    
    if(ans==-1){cout<<"item doesn't exist";}

    else{cout<<"item found at node:"<<ans;}

    return 0;
}