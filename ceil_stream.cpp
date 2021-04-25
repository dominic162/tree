/*
    Given a stream of numbers find ceil of every element;
*/

#include<iostream>
#include<set>
using namespace std;

int main(){

    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    set<int> st;
    cout<<"Ceil of all elements are: ";
    for(int i=0; i < n; ++i){

        if(st.lower_bound(arr[i]) != st.end()){
            cout<<(*st.lower_bound(arr[i]))<<" ";
        }
        else{
            cout<<"-1 ";
        }
        st.insert(arr[i]);
    }


    return 0;
}