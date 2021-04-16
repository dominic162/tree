/*
    Given inorder and preorder traversal,find tree;
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
        int prein = 0;

        node* make_tree(int* in,int* pre, int si, int ei);

        void postorder(node* root);
};

int main(){
    
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int* in = new int[n];
    int* pre = new int[n];

    cout<<"Enter inorder traversal: ";
    for(int i=0;i<n;++i){
        cin>>in[i];
    }

    cout<<"Enter pre-order traversal: ";
    for(int i=0;i<n;++i){
        cin>>pre[i];
    }

    solution sl;
    node* root = sl.make_tree(in, pre, 0 , n-1);

    cout<<"post-order traversal is: ";
    sl.postorder(root);

    return 0;
}

node* solution::make_tree(int* in,int* pre, int si, int ei){

    if(si > ei){
        return NULL;
    }

    node* root = new node(pre[prein++]);

    int index=0;
    for(int i=si;i<=ei;++i){
        if(in[i] == root->data){
            index = i;
            break;
        }
    }

    root->left = make_tree(in, pre, si, index-1);

    root->right = make_tree(in,pre , index+1, ei);

    return root;


}

void solution::postorder(node* root){

    if(root == NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return ;
}