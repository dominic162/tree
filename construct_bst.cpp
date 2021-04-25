/*
    Given pre-order traversal , construct BST from pre-order traversal;
*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *left , *right;
        node(int d):data(d),left(NULL),right(NULL){}
};

class solution{
    public:
        node* tree_make(int* arr, int s,int e);

        void inorder(node* root);
};

int main(){
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int* arr = new int[n];
    
    cout<<"Enter preorder traversal: ";
    for(int i=0 ; i < n; ++i){
        cin>>arr[i];
    }
    solution sl;
    node* root = sl.tree_make(arr,0,n-1);
    cout<<"Inorder traversal: ";
    sl.inorder(root);

    return 0;
}

node* solution::tree_make(int* arr ,  int s ,int e){

    if(s > e){
        return NULL;
    }

    node* root = new node(arr[s]);
    
    int id = -1;
    for(int i = s+1 ; i <= e;++i){
        if(arr[i] > arr[s]){
            id = i;
            break;
        }
    }

    if(id == -1){
        root->left = tree_make(arr, s+1, e);
    }
    else{
        root->left = tree_make(arr, s+1 ,id-1);
        root->right = tree_make(arr, id ,e );
    }

    return root;
}

void solution::inorder(node* root){
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}