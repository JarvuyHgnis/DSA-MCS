// A BT in which for each node, value of all the node in left subtree is lesser( or equal in case of duplicates) 
// and value of all nodes in right subtree is greater.

// Our 1st approach can be cheacking for each node if the subtrees are lesser or greater than the node's value
   // further we can reduce it by checking with the max in left subtree and min in right subtree
   // TC = O(n^2)

// We can check for each node with a dynamic upper and lower bound range if they lie in the range then it is a BST otherwise it's not
   // it will only traverse the nodes once so TC = O(n)

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

// bool isSubtreeLesser(node* root, int value) {
//     if(root == NULL) return true;
//     if(root->data <= value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value)) return true;
//     else return false;
// }

// bool isSubtreeGreater(node* root, int value) {
//     if(root == NULL) return true;
//     if(root->data >= value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value)) return true;
//     else return false;
// }

// bool isBST(node* root) {
//     if(root == NULL) return true;
//     if(isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data) && isBST(root->left) && isBST(root->right)) return true;
//     else return false;
// }

bool isBSTUtilityFun(node* root, int minValue, int maxValue) {
    if(root == NULL) return true;
    if(root->data > minValue && root->data < maxValue && isBSTUtilityFun(root->left, minValue, root->data) && isBSTUtilityFun(root->right, root->data, maxValue)) return true;
    else return false;
}

bool isBST(node* root){
    return isBSTUtilityFun(root, INT_MIN, INT_MAX);
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
    cout<<isBST(root)<<endl;
}
