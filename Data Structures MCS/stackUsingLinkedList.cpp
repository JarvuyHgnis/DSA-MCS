#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* link;
};
struct node* top = nullptr;
// implementing through insertion and removal from the beginning
void push(int x){
    node* temp = new node();
    temp->data = x;
    temp->link = top;
    top = temp;
}

void pop(){
    node* temp;
    if(top==NULL) return;
    temp = top;
    top = top->link;
    delete temp;
}

int Top(){
    if(top==NULL) return -1;
    return top->data;
}

bool isEmpty(){
    if(top==NULL) return true;
    return false;
}

void print(){
    node* temp = top;
    cout<<"Stack : ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}
int main(){
    push(2);
    print();
    push(4);
    print();
    cout<<"Top "<<Top()<<endl;
    pop();
    push(6);
    print();
    cout<<"Top "<<Top()<<endl;
    cout<<"isEmpty "<<isEmpty()<<endl;
    push(8);
    pop();
    print();
    pop();
    pop();
    cout<<"isEmpty "<<isEmpty()<<endl;
}
// expected output
// Stack : 2 
// Stack : 4 2
// Top 4
// Stack : 6 2
// Top 6
// isEmpty 0
// Stack : 6 2
// isEmpty 1