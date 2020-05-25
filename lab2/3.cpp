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

int findMinInTree(Tree* node){

    Tree* temp = node;

    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp->value;
}

Tree* addToBST(Tree* node, int value){
    if(node == NULL) {
        node = new Tree;
        node->value = value;
    }
    else if(node->value > value){
        node->left = addToBST(node->left, value);
    }
    else if(node->value < value){
        node->right = addToBST(node->right, value);
    }

    return node;
}

Tree* deleteFromBST(Tree* node, int value){
    if(node == NULL) return node;

    if(value < node->value){
        node->left = deleteFromBST(node->left, value);
    } else if (value > node->value){
        node->right = deleteFromBST(node->right, value);
    } else { // value = node->value

        if(node->right ==NULL){
            Tree* temp = node->left;
            delete node;
            return temp;
        }
        else if(node->left == NULL){
            Tree* temp = node->right;
            delete node;
            return temp;
        }else {

            int infixSuccessor = findMinInTree(node->right);
            node->value = infixSuccessor;

            node->right = deleteFromBST(node->right, infixSuccessor);
        }
    }
    return node;
    
}

int main() {
    Tree* root = NULL;

    int input[] = {14,15,4,9,7,18,3,5,16,4,20,17,9,14,5,8,6};

    for(int i = 0; i < 17; i++){
        root = addToBST(root, input[i]);
    }

    cout<<"----------- inorder before deleting ----------\n";
    inorder(root);
    end;

    for(int i = 0; i < 17; i++){
        root = deleteFromBST(root, input[i]);
        cout<<"----------- inorder after deleting "<<input[i]<<" ----------\n";
        if(root) inorder(root);
        end;
    }

    return 0;
}
