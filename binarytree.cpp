#include<iostream>
using namespace std;


class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            this->data=d;
            left = right =NULL;
        }
};

class binarytree{

    public:

        node* head;

        void intrav(node* temp= this->head){
            if(temp==NULL){
                return ;
            }

            intrav(temp->left);
            cout<<temp->data<<" ";
            intrav(temp->right);

            return ;
        }

        void pretrav(node* temp=head)

        binarytree(){
            this->head=NULL;
        }

};

int main(){
    return 0;
}