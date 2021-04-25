/*
    Given a binary tree, find floor of a value given.
    Floor means value equal or less than the given value;
*/

#include<iostream>
#include<queue>
#include<vector>
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

        node* give_floor(node* root , int t);

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

    vector<int> v;
    int target;
    cout<<"\nEnter target: ";
    cin>>target;
    
    node* fl = bnt.give_floor(root , target);

    if(fl != NULL){
        cout<<"Floor is "<<fl->data;
    }
    else{
        cout<<"No smaller or equal element "<<target;
    }

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

node* bntree::give_floor( node* root , int target ){
    if(root == NULL){
        return NULL;
    }
    node* ans = NULL;

    while(root != NULL){

        if(root->data == target){
            return root;
        }
        else{
            if(root->data > target){
                root = root->left;
            }
            else{
                ans = root;
                root = root->right;
            }
        }

    }

    return ans;

}

