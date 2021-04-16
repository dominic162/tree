/*
    Given a binary tree check, check whether it follows child sum property (sum of child nodes must be equal to parent node);
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
        bool child_sum(node* temp);
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

    if(bt.child_sum(bt.give_root())){
        cout<<"Tree follows child sum property";
    }
    else{
        cout<<"Tree doesn't follows child sum property";
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
        if(temp->left==NULL){
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

bool bntree::child_sum(node* temp){

    if(temp == NULL){
        return true;
    }

    if(temp->left == NULL && temp->right == NULL){
        return true;
    }

    int sum=0;
    sum = (temp->left == NULL?0:temp->left->data)+(temp->right == NULL?0:temp->right->data);

    return sum==temp->data && child_sum(temp->left) && child_sum(temp->right);

}

inline node* basic::give_root(){
    return root; 
}