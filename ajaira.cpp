
#include <bits/stdc++.h>
using namespace std;
#define max 60

void push(int stack[],int &top,int item)

 {
if(top==max-1){cout<<"overflow:"<<endl;return;}

top++;
stack[top]=item;

}

void print(const int stack[],int top)
{

    if(top==-1){cout<<"empty"<<endl;return;}

    for(int i=0;i<=top;i++)
{
    cout<<stack[i]<<" ";
}
  
}

int main() {
    
    int stack[max];
    int top=-1;
    push(stack,top,4);
      push(stack,top,7);
        push(stack,top,8);
      print(stack,top);
    
    return 0;
}
