#include<bits/stdc++.h>
using namespace std;

struct bstnode {
    int data;
    bstnode* left;
    bstnode* right;
};

bstnode* getNewNode(int x) {
    bstnode* newNode = new bstnode();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bstnode* insert(bstnode* root, int x) {
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

void search(bstnode* root, int x) {
    if(root == NULL) cout<<"Did Not Found "<<x<<endl;
    if(root->data == x) cout<<"Found "<<x<<endl;
    else if(x < root->data) {
        cout<<"Going Left ";
        return search(root->left,x);
    }
    else {
        cout<<"Going Right ";
        return search(root->right,x);
    }
}

void printLeaf(bstnode* root) {
    if(root == NULL) {
        cout<<"Nothing To Print!"<<endl;
        return;
    }
    if(!root->left && !root->right) {
        cout<<root->data<<" ";
        return;
    }
    if(root->left) {
        printLeaf(root->left);
    }
    cout<<endl;
    if(root->right) {
        printLeaf(root->right);
    }
}

void printInorder(bstnode* root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    bstnode* root = NULL; // creating an empty tree
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 0);
    root = insert(root, 30);
    search(root, 10);
    search(root, 25);
    search(root, 15);
    search(root, 5);
    // search(root, 35); // after executing this line, console doesn't shows further outputs
    printLeaf(root);
    cout<<endl;
    printInorder(root);
}