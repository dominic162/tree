#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }
};

class bst{
    private:
        node* head;
    
    public:

        void displayitems(node* temp){
            if(temp==NULL){
                return ;
            }
            cout<<temp->data<<" ";
            displayitems(temp->left);
            displayitems(temp->right);
        }

        void display(){

            displayitems(this->head);
        
        }

        void insert(int d){
            if(this->head==NULL){
                this->head=new node(d);
                return ;
            }

            node* parent;
            node* curr=this->head;
            while(curr!=NULL){
                parent=curr;
                if(curr->data>d){
                    curr=curr->left;
                }
                else{
                    if(curr->data<d){
                        curr=curr->right;
                    }
                    else{
                        return ;
                    }
                }
            }

            if(parent->data<d){
                parent->right=new node(d);
            }
            else{
                parent->left=new node(d);
            }

            return ;
        }

        int getsuccessor(node* root){
            root=root->right;
            while(root->left!=NULL){
                root=root->left;
            }
            return root->data;
        }

        node* deleted(node* root,int data){
            if(root==NULL)
                return root;
            
            if(root->data>data){
                root->left=deleted(root->left,data);
            }
            else{
                if(root->data<data){
                    root->right=deleted(root->right,data);
                }
                else{

                    if(root->left==NULL){
                        node* temp=root->right;
                        delete root;
                        return temp;
                    }

                    if(root->right==NULL){
                        node* temp=root->left;
                        delete root;
                        return temp;
                    }

                    int r=getsuccessor(root);
                    
                    root->data=r;

                    root->right=deleted(root->right,r);

                }
            }

        }
        
        void deletion(int d){
            this->head=deleted(this->head,d);
        }

        bst(){
            this->head=NULL;
        }


};


int main(){
    bst t1;
    int n;
    cout<<"Enter number of elements for insertion: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        t1.insert(d);
    }

    t1.display();

    int d;
    cout<<"Enter element for deletion: ";
    cin>>d;
    t1.deletion(d);
    t1.display();

    return 0;
}