// process of visiting each node in the tree exactly once in some order
// visit = reading/processing the data in a node

// DFS has preorder, inorder and postorder traversals
   // Queue is used in level order (BFS) traversal 
   // TC = O(n) as each node will be visited once
   // at any point in time there can be maximum n/2 elements in the queue as there can be maximum n/2 elements in the last level(of complete binary tree) 
   // so SC = O(n/2) = O(n) in Worst and Avg cases

// BFS is known as level order traversal in trees
   // Stack is used in DFS traversal
   // TC = O(n) one function call to each node when we were printing that node
   // SC = O(h) or O(n-1) = O(n) in worst case, where h is height of the tree and in worst case it can be "n-1" 
   // in best/avg case SC = O(log n)

#include<bits/stdc++.h>
using namespace std;

struct node {
    char data;
    node* left;
    node* right;
};

node* getNewNode(char x) {
    node* newNode = new node();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* root, char x) {
    if(root == NULL) { // empty tree
        root = getNewNode(x);
        return root;
    }
    else if(x <= root->data) {
        root->left = insert(root->left, x);
    }
    else {
        root->right = insert(root->right, x);
    }
}

void levelOrder(node* root) {
    if(root == NULL) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()) { // while there is atleast one discovered node in the queue
        node* current = q.front();
        cout<<current->data<<" ";
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        q.pop(); // removing the element at front
    }
    cout<<endl;
}

void printInorder(node* root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPreorder(node* root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(node* root) {
    if(root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

int main() {
    node* root = NULL; // creating an empty tree
    root = insert(root, 'F');
    root = insert(root, 'D');
    root = insert(root, 'E');
    root = insert(root, 'J');
    root = insert(root, 'G');
    root = insert(root, 'B');
    root = insert(root, 'C');
    root = insert(root, 'K');
    root = insert(root, 'A');
    root = insert(root, 'I');
    root = insert(root, 'H');
    printInorder(root);
    cout<<endl;
    printPreorder(root);
    cout<<endl;
    printPostorder(root);
    cout<<endl;
    levelOrder(root);
}

// outputs
// A B C D E F G H I J K 
// F D J B E G K A C I H