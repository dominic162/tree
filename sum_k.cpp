/*
    Given a binary tree, find all path with sum s;
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

        void print_path(node* root , vector<int> vr, int s);

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
    int s;
    cout<<"Enter sum: ";
    cin>>s;
    bnt.print_path(root, v, s);
 

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


void bntree::print_path(node* root,vector<int> v, int s){
    if(root == NULL){
        return ;
    }

    s = s-root->data;
    v.push_back(root->data);
    if(s == 0){
        cout<<"\n";
        for(int i=0; i < v.size();++i){
            cout<<v[i]<<" ";
        }
    }

    print_path(root->left , v ,s);
    print_path(root->right , v ,s);

    return ;

}

