/*
    Given a binary tree, do it spiral traversal;
                1
             /     \
            2        3
           /  \     /  \
          4    5   6   7 
         / \   /
        8   9  10

        its spiral traversal is:  1 3 2 4 5 6 7 10 9 8; 
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

        void spiral_print(node* temp);

        void spiral_print_eff(node* temp);

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

    bt.spiral_print(bt.give_root());

    cout<<endl;

    bt.spiral_print_eff(bt.give_root());

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


void bntree::spiral_print(node* root){

    if(root == NULL){
        return ;
    }

    bool ltr=true;
    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        int count=q.size();
        stack<node*> st;
        node* temp;
        for(int i=0;i<count;++i){
            temp = q.front();
            q.pop();

            if(ltr){
                cout<<temp->data<<" ";
                if(temp->left!=NULL){
                    st.push(temp->left);
                }
                if(temp->right!=NULL){
                    st.push(temp->right);
                }
            }

            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }

        if(st.empty()){
            ltr = true;
        }
        else{

            ltr = false;
            while(!st.empty()){
                cout<<st.top()->data<<" ";
                st.pop();
            }

        }

    }
    
}

inline node* basic::give_root(){
    return root; 
}

// Relatively efficient than other; it uses 2 stack;
void bntree::spiral_print_eff(node* root){

    if(root == NULL){
        return ;
    }

    stack<node*> st1,st2;
    
    st1.push(root);
    node* temp;
    while(!st1.empty() || !st2.empty()){

        while(!st1.empty()){
            temp = st1.top();
            st1.pop();

            cout<<temp->data<<" ";
            
            if(temp->left != NULL){
                st2.push(temp->left);
            }
            
            if(temp->right != NULL){
                st2.push(temp->right);
            }

        }

        while(!st2.empty()){
            
            //push in reverse direction in 2nd stack means first push right child then left;

            temp = st2.top();
            st2.pop();

            cout<<temp->data<<" ";

            if(temp->right != NULL){
                st1.push(temp->right);
            }

            if(temp->left != NULL){
                st1.push(temp->left);
            }

        }

    }
    return ;

}