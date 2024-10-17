// CASE 0 : Node has 0 child
   //deleting a leaf node is easy, just delete it's reference from the parent node
// deleting a non leaf node has 2 cases
   // CASE 1 : Node has only one child.
      // in such case the only child and all it's grand childrens will be attatched to the parent of the node that is to be deleted
   // CASE 2 : Node has 2 childs
      // in such case we can have 2 options to substitute the deleted node
      // OPTION 1 : minimum element in right subtree of that node(gets reduced to CASE 1 as min in right can't have left child), now delete the substituted element
      // OPTION 2 : maximum element in left subtree of the node(as it won't have any right child, reducing it to CASE 1) now delete the substituted element


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
    root = deleteNode(root, 50);
    printInorder(root);
    cout<<endl;
    root = deleteNode(root, 10);
    printInorder(root);
    cout<<endl;
    root = deleteNode(root, 5);
    printInorder(root);
    cout<<endl;
}

// output
// 0 5 10 15 20 25 30 50 
// 0 5 10 15 20 25 30
// 0 5 15 20 25 30
// 0 15 20 25 30
