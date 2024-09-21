#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void push(int x){
    if(top == MAX_SIZE-1) {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    A[++top] = x;
}

void pop() {
    if(top==-1){
        cout<<"Stack Empty"<<endl;
        return;
    }
    top--;
}

int Top() {
    return A[top];
}

int print() {
    cout<<"Stack : ";
    for(int i=0; i<=top; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {
    push(2);
    print();
    push(5);
    print();
    push(10);
    print();
    pop();
    print();
    push(12);
    print();
}