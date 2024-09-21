#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

node* head; // global variable

void insertAtHead(int x){
    // for inserting a node at beginning
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if(head==NULL){
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTail(int x){
    // for inserting a node at the end
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = temp;
    temp->prev = tail;
}

void forwardPrint(){
    // for printing the doubly linked list
    node* temp = head;
    cout<<"List is : ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void reversePrint(){
    // for printing the list backwards without actually reversing it
    node* temp = head;
    if(temp == NULL) return; // empty list, exit
    while(temp->next != NULL){ // Going to last node
        temp = temp->next;
    }
    cout<<"Reverse List is : ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

int main(){
    // node* head; // local vbvariable
    head = NULL;
    insertAtHead(4);
    insertAtHead(2);
    insertAtHead(0);
    insertAtTail(6);
    insertAtTail(8);
    forwardPrint();
    reversePrint();
}