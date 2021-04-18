/*
    Given a binry tree; Find mirror of it;
*/

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d):data(d),left(NULL),right(NULL){
        }
};

class bntree{

    public:

        node* make_btree(int arr[], int n);

        void inorder(node* root);

        node* mirror(node* root);
};


int main(){

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int arr[n];
    
    cout<<"Enter data of nodes in level order format;\nEnter -1 for NULL: ";
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    bntree bnt;
    node* root = bnt.make_btree( arr , n );
    cout<<"Inorder traversal of tree: ";
    bnt.inorder(root);

    node* clone = bnt.mirror(root);

    cout<<"\nInorder traversal of mirror: ";
    bnt.inorder(clone);

    return 0;
}

node* bntree::make_btree(int arr[] , int n){

    node* head = NULL;
    queue<node*> q;

    for(int i=0; i < n; ++i){

        if(q.empty()){
            head = new node(arr[i]);
            q.push(head);
        }
        else{
            node* curr = q.front();

            if(curr->left == NULL){
                if(arr[i] != -1){
                    curr->left = new node(arr[i]);
                    q.push(curr->left);
                }
            }

            ++i;
            if(i==n){
                break;
            }

            if(curr->right == NULL){
                if(arr[i] != -1){
                    curr->right = new node(arr[i]);
                    q.push(curr->right);
                }
                q.pop();
            }


        }
    }
    return head;
}

void bntree::inorder(node* root){

    if(root == NULL)
        return ;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

node* bntree::mirror(node* root){
    if(root == NULL){
        return NULL;
    }

    node* clone = new node(root->data);
    clone->left = mirror(root->right);
    clone->right = mirror(root->left);

    return clone;

}