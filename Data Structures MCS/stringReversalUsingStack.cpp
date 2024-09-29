#include<bits/stdc++.h>
using namespace std;

void reverseStr(char *C, int n) {
    stack<char> S;
    // loop for push
    for(int i=0; i<n; i++){
        S.push(C[i]);
    }
    // loop for pop
    for(int i=0; i<n; i++){
        C[i] = S.top(); // overwrite C
        S.pop(); // pop top element
    }
}

void reverseLL() {
    if(head == NULL) return;
    stack<struct node*> S;
    node* temp = head;
    while(temp != NULL) {
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

int main() {
    char C[51];
    cout<<"Enter a string : "<<endl;
    gets(C);
    reverseStr(C,strlen(C));
    cout<<"Output : "<<C<<endl;
}