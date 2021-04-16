/*
    Given a tree, check whether it is balanced or not;
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
        int is_balanced(node* temp);
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

    if(bt.is_balanced(bt.give_root()) == -1){
        cout<<"Tree isn't balanced";
    }
    else{
        cout<<"Tree is balanced";
    }

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

int bntree::is_balanced(node* temp){

    if(temp == NULL){
        return 0;
    }

    int lh;
    lh = is_balanced(temp->left);
    if(lh == -1){
        return -1;
    }

    int rh;
    rh = is_balanced(temp->right);

    if(rh == -1){
        return -1;
    }

    if(abs(lh-rh)>1){
        return -1;
    }
    else{
        return max(lh,rh)+1;
    }

}