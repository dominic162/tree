/*
    Given a binary tree, find its diagonal traversal;
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

        node* make_btree(int arr[], int n);

        void inorder(node* root);

        void diagonal_help(node* root, vector<vector<int>> &vr, int k,int &size);

        void diagonal_print(node* root);
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
    cout<<"\nDiagonal print of tree is: \n";
    bnt.diagonal_print(root);


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

void bntree::diagonal_print(node* root){
    if(root == NULL){
        return ;
    }
    vector<vector<int>> vr;
    int k=0 , size=0;
    diagonal_help(root , vr, k ,size);

    for(int i = 0 ;i < vr.size(); ++i){

        for(int j = 0; j < vr[i].size(); ++j){
            cout<<vr[i][j]<<" ";
        }
        cout<<endl;

    }
    return ;

}

void bntree::diagonal_help(node* root , vector<vector<int>> &vr, int k, int &size){
    if(root == NULL){
        return ;
    }

    if(k == size){
        vector<int> v1;
        vr.push_back(v1);
        ++size;
    }

    vr[k].push_back(root->data);

    diagonal_help(root->left, vr, k+1, size);

    diagonal_help(root->right, vr, k, size);

    return ;
}