/*
    Given a binary tree, find its diameter;
*/

#include<iostream>
#include<queue>
#include<stack>
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

        int find_diameter(node* root,int &m);

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
    int m = 0;
    int temp = bt.find_diameter(bt.give_root(),m);
    cout<<"Diameter is "<<m;

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


inline node* basic::give_root(){
    return root; 
}



int bntree::find_diameter(node* root,  int &m){

    if(root == NULL){
        return 0;
    }

    int lh,rh;

    lh = find_diameter(root->left ,  m);

    rh = find_diameter(root->right , m);

    int ans = 1+lh+rh;
    m = max(m, ans);

    return 1+max(lh,rh);

}
