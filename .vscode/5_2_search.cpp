
#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *next;

};

int traverse(Node *ptr,int item)
{
int count=1;
    while(ptr!=NULL)
    {
        if(ptr->data==item){return count;}

        
        ptr=ptr->next;
        count++;
    }
     return -1;
}
   

int main() {
    int k;


    cin>>k;
   Node *head;
   Node *second;
   Node *third;
   Node *fourth;

head=(Node*)malloc(sizeof(Node));    
second=(Node*)malloc(sizeof(Node)); 
third=(Node*)malloc(sizeof(Node)); 
fourth=(Node*)malloc(sizeof(Node)); 

head->data=10;
head->next=second;

second->data=20;
second->next=third;

third->data=30;
third->next=fourth;

fourth->data=40;
fourth->next=NULL;


  int ans=traverse(head,k);

if(ans!=-1){cout<<"item is found at node : "<<ans;}

else cout<<"item is not found at any node :"<<endl;


    return 0;
}
