#include <bits/stdc++.h>

using namespace std;

class Tree{
public:
    int data;
    Tree* left;
    Tree* right;
};

Tree* create(int data){
    Tree* temp = new Tree;
    temp->data = data;
    temp->left = NULL;
    temp->right =NULL;

    return temp;
}
/*Inorder recursive............
void inOrder(Tree* node){
    if(node==NULL)
        return;
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}*/

//Iterative InOrder...............
void inOrder(Tree* node){
    stack <Tree*> a;
    Tree* curr = node;
    while(1){
        while(curr){
            a.push(curr);
            curr = curr->left;
        }
        if(a.empty())
            return;
        curr = a.top();
        cout<<curr->data<<" ";
        a.pop();
        curr = curr->right;
    }
}

int main(){
    Tree* root = create(6);
    root->left = create(4);
    root->right = create(9);
    root->left->left = create(3);
    root->left->right = create(5);
    root->right->left = create(7);
    root->right->right = create(10);

    inOrder(root);
    cout<<endl;
    
    return 0;
}
