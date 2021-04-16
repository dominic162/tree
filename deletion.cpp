//deletion of node from binary tree
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    /* data */
    int data;
    node *left;
    node *right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void insert(node *rroot, int d){
    node *p;
    while (rroot != NULL){
        p = rroot;
        if (d > rroot->data){
            rroot = rroot->right;
        }
        else{
            rroot=rroot->left;
        }
    }
    if(d>p->data){
        p->right=new node(d);
    }
    else
    {
        p->left=new node(d);
    }
    return ;
}

int findmax(node* root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}

node* deleteit(node* rroot,int d){
    if(rroot==NULL){
        return NULL;
    }
    else{
        if(d>rroot->data){
            rroot->right=deleteit(rroot->right,d);
        }
        else{
            if(d<rroot->data){
                rroot->left=deleteit(rroot->left,d);
            }
            else{
                if(rroot->left!=NULL && rroot->right!=NULL){
                    int value=findmax(rroot->left);
                    rroot=deleteit(rroot,value);
                    rroot->data=value;                
                }
                else{
                    if(rroot->left!=NULL){
                        node *temp=rroot->left;
                        delete(rroot);
                        return temp;
                    }
                    else{
                        node* temp=rroot->right;
                        delete(rroot);
                        return temp;
                    }
                }
            }
        }
    }
    return rroot;
}

void inordertraversal(node* root){
    queue<node*> q1;
    node* temp;
    if(root!=NULL){
        q1.push(root);
    }
    while(!q1.empty()){
        temp=q1.front();
        q1.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q1.push(temp->left);
        }
        if(temp->right!=NULL){
            q1.push(temp->right);
        }
    }
    return ;
}

int main()
{
    int i, n, d,deldata,ed,ddata;
    cout << "Enter number of nodes in tree:- ";
    cin >> n;
    node *root;
    cout << "Enter data:- ";
    cin >> d;
    root = new node(d);
    for (i = 1; i < n; i++)
    {
        cin >> d;
        insert(root, d);
    }

    cout<<"Enter number of elements to be deleted:- ";
    cin>>ed;
    for(i=0;i<ed;i++){
        cin>>ddata;
        root=deleteit(root,ddata);
        inordertraversal(root);
    }


    return 0;
}