// no. of edges in longest path from root to leaf node
// for a first child if root, the height will be 2(has 2 children and 2 grandchildren) and depth will be one(one parent as root)
// height is calculated as distance from leaf node and depth is calculated as distance from root
// height of tree = height of left subtree + height of right subtree + 1.

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

int height(bstnode* root) { // TC = O(n) where n = number of nodes
    if(root == NULL) {
        return -1; // since we are counting no. of edges, it will be 0 if we will be counting nodes
    }
    return max(height(root->left),height(root->right)) + 1;
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
    root = insert(root, 50);
    cout<<height(root)<<endl;
}