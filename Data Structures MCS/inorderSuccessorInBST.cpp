// we can simply do that while traversing inorder an tracking the successor there, but it would be costly TC = O(n)
// we wish for O(h) at most in a bst since h = log n which will give TC = O(log n)
// inorder successor of a node can be found by applying the cases discussed below
    // CASE 1 : Node has a right subtree
        // go deep to leftmost node in right subtree (find min in right subtree)
    // CASE 2 : No right subtree
        // go to the nearest ancestor for which given node would be in left subtree (or nearest ancestor greater than the node)


#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* getNewNode(int x) {
    node* newNode = new node();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* root, int x) {
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

node* findMin(node* root){
	while(root->left != NULL) root = root->left;
	return root;
}

node* deleteNode(node* root, int x){
    if(root == NULL) return root;
    else if(x < root->data) {
        root->left = deleteNode(root->left, x);
    }
    else if(x > root->data) {
        root->right = deleteNode(root->right, x);
    }
    else { // found x, ready to be deleted
        // CASE 0 : 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // CASE 1 : 1 child
        else if(root->left == NULL) {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL) {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        // CASE 2 : 2 child
        else {
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
}

void printInorder(node* root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

node* find(node* root, int x){
    if(root == NULL) return NULL;
    if(x == root->data) return root;
    else if(x < root->data) {
        find(root->left, x);
    }
    else {
        find(root->right,x);
    }
}

node* getInorderSuccessor(node* root, int x) {
    // search the node - O(n)
    node* current = find(root, x);
    if(current == NULL) return NULL;
    // CASE 1 : Node has right subtree
    if(current->right != NULL) {
        return findMin(current->right);
    }
    // CASE 2 : No right subtree
    else {
        node* successor = NULL;
        node* ancestor = root;
        while(ancestor != current) {
            if(current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

int main() {
    node* root = NULL; // creating an empty tree
    root = insert(root, 25);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 0);
    root = insert(root, 30);
    root = insert(root, 50);
    printInorder(root);
    cout<<endl;
    node* temp = getInorderSuccessor(root, 5);
    cout<<temp->data<<endl;
    printInorder(root);
    cout<<endl;
    root = deleteNode(root, 50);
    temp = getInorderSuccessor(root, 5);
    cout<<temp->data<<endl;
    printInorder(root);
    cout<<endl;
    root = deleteNode(root, 10);
    temp = getInorderSuccessor(root, 5);
    cout<<temp->data<<endl;
    printInorder(root);
    cout<<endl;
    root = deleteNode(root, 5);
    temp = getInorderSuccessor(root, 25);
    cout<<temp->data<<endl;
    printInorder(root);
    cout<<endl;
}