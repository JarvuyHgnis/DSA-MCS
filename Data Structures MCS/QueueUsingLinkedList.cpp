#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};
node* front = NULL;
node* rear = NULL;

void enqueue(int x) {
    cout<<"Enquiuing "<<x<<endl;
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue() {
    cout<<"Dequiuing"<<endl;
    node* temp = front;
    if(front == NULL) return;
    if(front == rear) {
        front = rear =NULL;
    }
    else {
        front = front->next;
    }
    delete temp;
}

bool isEmpty() {
    if(front == NULL) return true;
    return false;
}

void frontVal() {
    if(isEmpty()) cout<<"Empty Queue"<<endl;
    else cout<<front->data<<endl;
}

void print() {
    node* temp = front;
    cout<<"Elements are : ";
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    enqueue(2); print();
    enqueue(4); print();
    enqueue(6); print();
    dequeue(); print();
    enqueue(8); print();
    frontVal();
    isEmpty();
}