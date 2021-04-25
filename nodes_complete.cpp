/*
    Given a complete binary tree , find no of nodes in it;
*/

#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
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

        node* make_btree(const vector<int> &vr, int n);

        void inorder(node* root);

        int height(node* root);
};


int main(){

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    vector<int> vr(n,0);
    
    cout<<"Enter data of nodes in level order format;\nEnter -1 for NULL: ";
    for(int i=0;i<n;++i){
        cin>>vr[i];
    }

    bntree bnt;
    node* root = bnt.make_btree( vr , n );
    cout<<"Inorder traversal of tree: ";
    bnt.inorder(root);

    cout<<"\nNo of nodes in complete binary tree is "<<bnt.height(root);

    return 0;
}

node* bntree::make_btree(const vector<int> &vr , int n){

    node* head = NULL;
    queue<node*> q;

    for(int i=0; i < n; ++i){

        if(q.empty()){
            head = new node(vr[i]);
            q.push(head);
        }
        else{
            node* curr = q.front();

            if(curr->left == NULL){
                if(vr[i] != -1){
                    curr->left = new node(vr[i]);
                    q.push(curr->left);
                }
            }

            ++i;
            if(i==n){
                break;
            }

            if(curr->right == NULL){
                if(vr[i] != -1){
                    curr->right = new node(vr[i]);
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

int bntree::height(node* root){

    if(root == NULL){
        return 0;
    }

    int lh=0,rh=0;

    for( node* temp = root ; temp != NULL ; temp = temp->left){
        ++lh;
    }

    for(node* temp = root; temp!=NULL; temp =temp->right){
        ++rh;
    }

    if(lh == rh){
        return pow(2,lh)-1;
    }

    return 1 + height(root->left) + height(root->right);

}