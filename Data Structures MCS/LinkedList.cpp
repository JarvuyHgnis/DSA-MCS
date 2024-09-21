#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};
struct node* head; // global variable, can be accessed from anywhere

// void insertAtBeginning(int x){ 
//     // insert at beginning
//     struct node* temp = new node();
//     temp->data = x;
//     temp->next = head;
//     head = temp;
// }

// void insertAtN(int data, int n){ 
//     // insert a node at nth position
//     node* temp = new node();
//     temp->data = data;
//     if(n==1){
//         temp->next = head;
//         head = temp;
//     }
//     else {
//         node* location = head;
//         n = n-2;
//         while(n--){
//             location = location->next; 
//         } 
//         temp->next = location->next;
//         location->next = temp;
//     }
// }

// void insertAtEnd(int data){ 
//     // insert a node at end
//     node* temp1 = new node();
//     temp1->data = data;
//     temp1->next = NULL;
//     if(head==NULL) head = temp1;
//     else {
//         node* temp2 = head;
//         while(temp2->next != NULL)
//             temp2 = temp2->next;
//         temp2->next = temp1;
//     }
// }

struct node* insertAtEnd(node* head,int data){ 
    // insert a node at end
    node* temp1 = new node();
    temp1->data = data;
    temp1->next = NULL;
    if(head==NULL) head = temp1;
    else {
        node* temp2 = head;
        while(temp2->next != NULL)
            temp2 = temp2->next;
        temp2->next = temp1;
    }
    return head;
}

// void deletee(int n){
//     // Delete a node at n
//     node* temp1 = head;
//     if(n==1){
//         temp1 = temp1->next;
//         head = temp1;
//         return;
//     }
//     n = n-2;
//     while(n--){
//         temp1 = temp1->next;
//     }
//     node* temp2 = temp1->next;
//     temp1->next = temp2->next;
// }

// void reverseIteration(){
//     // Reverse a linked list using iteration
//     struct node *current,*prev,*next;
//     current = head;
//     prev = NULL;
//     while(current != NULL){
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     head = prev;
// }

void reverseRecursion(node* p){
    if(p->next == NULL){
        head =  p;
        return;
    }
    reverseRecursion(p->next);
    p->next->next = p;
    p->next = NULL;
}

// void print(){ 
//     // Print using simple iteration
//     struct node* temp = head;
//     cout<<"List is : ";
//     while(temp != NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next; 
//     } 
//     cout<<endl;
// }

void printRecursive(node* p){
    // Print using recursion
    if(p==NULL) return; // exit condition
    cout<<p->data<<" "; // print value of node
    printRecursive(p->next); // recursive call
}

void printReverse(struct node* p){
    // Print a list reverse without reversing the list
    if(p==NULL) return; // exit condition
    printReverse(p->next); // recursive call
    cout<<p->data<<" "; // print value of node
}

int main() {
    // node* head; // Local pointer
    head = NULL; // Empty list
    // cout<<"Enter the amount of numbers"<<endl;
    // int n,x; // For inserting at beginning
    // cin>>n; 
    // for(int i=0; i<n; i++){  
    //     // cout<<"Enter the number"<<endl;
    //     cin>>x;
    //     insertAtBeginning(x);
    //     print();
    // }
    // insertAtN(2,1); // For inserting at any position
    // insertAtN(3,2);
    // insertAtN(4,1);
    // insertAtN(5,2);
    // cout<<"Before deletion ";
    // print();
    // insertAtEnd(2); // For deleting a node at nth position
    // insertAtEnd(4);
    // insertAtEnd(6);
    // insertAtEnd(8);
    // cout<<"Before deletion ";
    // print();
    // deletee(2); // For deletion of nth node
    // deletee(3);
    // cout<<"\nAfter Deletion ";
    // print();
    // reverseIteration(); // For reversal of list
    // cout<<"After Reversal ";
    // print();
    head = insertAtEnd(head,2); // For deleting a node at nth position
    head = insertAtEnd(head,4);
    head = insertAtEnd(head,6);
    head = insertAtEnd(head,8);
    cout<<"List is : ";
    printRecursive(head);
    cout<<endl;
    cout<<"Reverse List is : ";
    printReverse(head);
    cout<<endl;
    reverseRecursion(head);
    cout<<"Reversed List using Recursion is : ";
    printRecursive(head);
    cout<<endl;
    cout<<"Reverse List is : ";
    printReverse(head);
    cout<<endl;
}