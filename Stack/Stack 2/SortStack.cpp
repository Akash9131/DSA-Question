#include<iostream>
#include<Stack>
using namespace std;

void sortedInsert(stack<int>& st, int data) {
    // base case
    if( st.empty() || st.top() < data) {
        st.push(data);
        return;
    }

    int topElement = st.top();
    st.pop();


    //resursiv call
    sortedInsert(st,data);

    st.push(topElement);

}

void sortAstack(stack<int>& st) {
    //Base case

    if(st.empty())
    return;

    int topElement =  st.top();
    st.pop();

    //recursiv call
    sortAstack(st);

    //sorted insert
    sortedInsert(st,topElement);
}



int main()
{
    stack<int>st;

    st.push(2);
    st.push(1);
    st.push(4);
    st.push(3);

     sortAstack(st);
    cout<<"Printing ans "<<endl;

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}