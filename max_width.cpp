/*
    Given a binary tree, find its max width;
*/

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d):data(d),left(NULL),right(NULL){}
};

class basic{
    private:
        node* root;
    public:
        node* give_root();

        void insert(int d);

        basic():root(NULL){}
};

class bntree:public basic{
    public:
        int max_width(node* temp);
};

int main(){
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int x;

    bntree bt;
    cout<<"Enter nodes: ";
    for(int i=0 ; i<n ; i++){
        cin>>x;
        bt.insert(x);
    }

    cout<<"Max width of binary tree is "<<bt.max_width(bt.give_root());

    return 0;
}

void basic::insert(int d){
    if(root == NULL){
        root = new node(d);
        return ;
    }
    node* temp = NULL;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left == NULL){
            temp->left = new node(d);
            return ;
        }
        else{
            q.push(temp->left);
        }
        if(temp->right == NULL){
            temp->right = new node(d);
            return ;
        }
        else{
            q.push(temp->right);
        }
    }
}

inline node* basic::give_root(){
    return root; 
}

int bntree::max_width(node* temp){

    if(temp==NULL){
        return 0;
    }

    queue<node*> q;
    int width = 0 ;
    q.push(temp);

    while(!q.empty()){

        int size = q.size();
        width = max(width, size);
        node* help;

        for(int i=0; i<size;++i){
            help = q.front();
            q.pop();
            if(help->left!=NULL){
                q.push(help->left);
            }
            if(help->right!=NULL){
                q.push(help->right);
            }
        }
    }
    return width;

}