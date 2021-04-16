/*
    Print level order traversal of binary tree with each level in new line;
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

class bntree{
    private:
        node* root;

    public:

        void insert(int d);

        void level_print();

        void level_print2();

        bntree():root(NULL){}
};

int main(){

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    int x;
    bntree bnt;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;++i){
        cin>>x;
        bnt.insert(x);
    }

    bnt.level_print();
    cout<<"\n";
    bnt.level_print2();


    return 0;
}

void bntree::insert(int d){
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
//1st method pushing null after every line
void bntree::level_print(){
    cout<<"Level order traversal is:\n";
    queue<node*> q;
    if(root == NULL){
        return ;
    } 

    q.push(root);
    q.push(NULL);

    node* temp=NULL;
    while(q.size()>1){

        temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<"\n";
            q.push(NULL);
            continue;
        }
        cout<<temp->data<<" ";        
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    return ;
}
// without pushing null
void bntree::level_print2(){

    if(root==NULL){
        return ;
    }

    queue<node*> q;
    node* temp;
    q.push(root);

    while(!q.empty()){

        int count = q.size();
        for(int i=0; i < count; ++i){

            temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        cout<<endl;
    }
    return ;
}