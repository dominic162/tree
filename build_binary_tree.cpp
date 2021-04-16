#include<iostream>
using namespace std;
class bstnode{
    public:
        int data;
        bstnode *left;
        bstnode *right;
        bstnode(int value,bstnode* l,bstnode* r){
            this->data=value;
            this->left=l;
            this->right=r;
        }
};
bstnode* insertnode(bstnode *root,int data){ //insertion of a node in a BST
    if(root==NULL){
        root=new bstnode(data,NULL,NULL);
        return root;
    }
    else{
        if(root->data>data){
            root->left=insertnode(root->left,data);
        }
        else{
            root->right= insertnode(root->right,data);
        }
    }
}
void preorder(bstnode* root){ // preorder traversal of a BST
    if(root==NULL){
        return ;
    }
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
    return ;
}
int main(){
    int n,a[100],i;
    cout<<"enter number of elements in tree:- ";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    bstnode *root=NULL;
    for(i=0;i<n;i++){
        root=insertnode(root,a[i]);
    }
    
    preorder(root);


    return 0;
}