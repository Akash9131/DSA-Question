#include<iostream>
#include<Stack>
using namespace std;
int main()
{
    int n;
    cin>>n;

    stack<int>st;

    while(n--){
        int data;
        cin>> data;
        st.push(data);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();

    }
    cout<<endl;
}