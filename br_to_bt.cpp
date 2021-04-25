/*
    Given a binary tree in bracket form, make it a tree;
*/

#include<iostream>
#include<string>
using namespace std;

class node{
    public:
        int data;
        node *left,*right;
        node(int d):data(d),left(NULL),right(NULL){
        }
};

class bntree{
    public:
        node* make_tree(string s, int &i, const int n);  

        void inorder(node* root);
};

int main(){

    string s;
    cout<<"Enter tree in bracket format: ";
    cin>>s;
    
    bntree bt;
    int i=0;
    node* root = bt.make_tree(s, i , s.size()); 

    bt.inorder(root);

    return 0;
}

node* bntree::make_tree(string s, int &i, const int n){
    if(i == n ){
        return NULL;
    }

    node* root = NULL;
    if(s[i] != '(' && s[i] !=')'){
        int d = s[i]-'0';
        root = new node(d);
        ++i;
    }

    if(i == n){
        return root;
    }

    if(s[i] == '('){
        root->left = make_tree(s,++i, n);
        ++i;
    }
    else{
        return root;
    }

    if(i == n){
        return root;
    }

    if(s[i] == '('){
        root->right = make_tree(s , ++i, n);
        ++i;
    }
    else{
        return root;
    }

    return root;

}

void bntree::inorder(node* root){
    begin:
        if(root == NULL){
            return ;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        root = root->right;
        goto begin;
}