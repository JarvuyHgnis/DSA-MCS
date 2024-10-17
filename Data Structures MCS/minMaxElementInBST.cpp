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

// int findMin(bstnode* root) {
//     if(root == NULL) {
//         cout<<"Nothing To Print!"<<endl;
//         return -1;
//     }
//     while(root->left != NULL) {
//         root = root->left;
//     }
//     return root->data;
// }

int findMin(bstnode* root) {
    if(root == NULL) {
        cout<<"Nothing To Print!"<<endl;
        return -1;
    }
    while(root->left == NULL) {
        return root->data;
    }
    return findMin(root->left); // search in left subtree
}


// int findMax(bstnode* root) {
//     if(root == NULL) {
//         cout<<"Nothing To Print!"<<endl;
//         return -1;
//     }
//     while(root->right != NULL) {
//         root = root->right;
//     }
//     return root->data;
// }

int findMax(bstnode* root) {
    if(root == NULL) {
        cout<<"Nothing To Print!"<<endl;
        return -1;
    }
    while(root->right == NULL) {
        return root->data;
    }
    return findMax(root->right); // search in right subtree
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
    cout<<findMax(root)<<endl;
    cout<<findMin(root)<<endl;
}