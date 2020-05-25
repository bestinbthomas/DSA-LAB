#include <bits/stdc++.h>
using namespace std;
#define end cout<<endl

struct Tree {
    int value;
    Tree* left;
    Tree* right;
};

void inorder(Tree* tree) {
    Tree* node = tree;

    if(node->left != NULL) inorder(node->left);

    cout<<node->value<<"\t";

    if(node->right != NULL) inorder(node->right);
}

void preorder(Tree* tree) {
    Tree* node = tree;

    cout<<node->value<<"\t";

    if(node->left != NULL) preorder(node->left);

    if(node->right != NULL) preorder(node->right);
}

void postorder(Tree* tree) {
    Tree* node = tree;

    if(node->left != NULL) postorder(node->left);

    if(node->right != NULL) postorder(node->right);

    cout<<node->value<<"\t";
}


int main() {
    /*
                            1
                    
                2                           3
        4               5           6               7
    */
    Tree* root = new Tree;
    root->value = 1;

    root->left = new Tree;
    root->right = new Tree;
    root->left->value = 2; 
    root->right->value = 3;

    root->left->left = new Tree;
    root->left->right = new Tree;
    root->left->left->value = 4;
    root->left->right->value = 5;

    root->right->left = new Tree;
    root->right->right = new Tree;
    root->right->left->value = 6; 
    root->right->right->value = 7;

    cout<<"----------- inorder ----------\n";
    inorder(root);
    end;

    cout<<"----------- preorder ----------\n";
    preorder(root);
    end;

    cout<<"----------- postorder ----------\n";
    postorder(root);
    end;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
