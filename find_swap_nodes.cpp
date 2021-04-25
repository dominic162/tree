/*
    Given a BST in which two nodes are swapped , find two nodes that are swapped; 
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

        void inorder(node* root,vector<node*> &vr);

        void give_swap(const vector<node*> &v,node* &one , node* &two);


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
    
    cout<<"Inorder traversal: ";
    vector<node*> intrav;
    bnt.inorder(root,intrav);

    node *one = NULL , *two = NULL;
    bnt.give_swap(intrav,one,two);

    cout<<"\nTwo nodes which are swapped are: "<<one->data<<" "<<two->data;

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

void bntree::inorder(node* root,vector<node*> &vr){

    if(root == NULL)
        return ;
    
    inorder(root->left,vr);
    vr.push_back(root);
    cout<<root->data<<" ";
    inorder(root->right,vr);

}

void bntree::give_swap(const vector<node*> &v,node* &one , node* &two){

    for(int i = 1 ;i < v.size(); ++i){

        if(v[i]->data < v[i-1]->data){
            if(one == NULL){
                one = v[i-1];
            }
            two = v[i];
        }

    }
    return ;

}

