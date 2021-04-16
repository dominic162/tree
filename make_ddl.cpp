/*
    Given a binary tree, make it a doubly linked list;
*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d):data(d){
            this->left = NULL;
            this->right = NULL;
        }
};


class solution{
    public:
        node* pre=NULL;
        
        node* make_ddl(node* root);

        void disp(node* head);
};

int main(){

    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(20);
    root->right->left = new node(30);
    root->right->right = new node(35);

    solution sl;

    node* head = sl.make_ddl(root);

    sl.disp(head);

    return 0;
}

node* solution::make_ddl(node* root){

    if(root == NULL){
        return NULL;
    }

    node* head = make_ddl(root->left);
    
    if(pre == NULL){
        head = root;
    }
    else{
        root->left = pre;
        pre->right = root;
    }
    pre = root;

    node* temp = make_ddl(root->right);

    return head;

}

void solution::disp(node* head){
    for(;head!=NULL; head=head->right){
        cout<<head->data<<" ";
    }
    return ;
}