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
/*Preorder recursive............
void preOrder(Tree* node){
    if(node==NULL)
        return;

    cout<<node->data<<" ";
    inOrder(node->left);    
    inOrder(node->right);
}*/

//Iterative preOrder...............
void preOrder(Tree* node){
    stack <Tree*> a;
    Tree* curr;
    a.push(node);
    while(!a.empty()){
        curr = a.top();
        cout<<curr->data<<" ";
        a.pop();
        if(curr->right)
            a.push(curr->right);
        if(curr->left)
            a.push(curr->left);
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

    preOrder(root);
    cout<<endl;
    
    return 0;
}
    