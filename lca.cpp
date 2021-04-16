/*
    Given a tree and two nodes, find lowest common ancestor between them;
*/

#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
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

        int lca(node* root,int n1,int n2);

        bool get_path(vector<int> &v1, node* root, int val);

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

    int n1,n2;
    cout<<"Enter nodes for which you have to find lowest common ancestor: ";
    cin>>n1>>n2;
    int answer = bt.lca(bt.give_root(), n1, n2);

    if(answer != -1){
        cout<<"LCA of "<<n1<<" and "<<n2<<" is "<<answer;
    }
    else{
        cout<<"Both roots must be present in tree to find lca";
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


inline node* basic::give_root(){
    return root; 
}


// gives lowest common ancestor and also path between root and nodes;
int bntree::lca(node* root, int n1 , int n2){

    vector<int> v1, v2;

    if(get_path(v1,root,n1) == false || get_path(v2,root,n2) == false){
        return -1;    
    }

    int i = v1.size()-1 , j = v2.size()-1;
    int pre = -1;
    for( ; (i >= 0)&&(j >= 0); ){

        if(v1[i] == v2[j]){
            pre = v1[i];
        }
        else{
            break;
        }

        --i;
        --j;
    }
    return pre;

}


//gives path and check if root exist in tree;
bool bntree::get_path(vector<int> &v1, node* root, int val){

    if(root == NULL){
        return false;
    }

    if(root->data == val){
        v1.push_back(root->data);
        return true;
    }

    if(get_path(v1,root->left,val) || get_path(v1,root->right,val)){
        v1.push_back(root->data);
        return true;
    }
    return false;

}