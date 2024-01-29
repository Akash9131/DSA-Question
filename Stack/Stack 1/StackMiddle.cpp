#include<iostream>
#include<Stack>
using namespace std;

void getMiddle(stack<int>& st, int totalSize) {
    if(totalSize == 0){
        cout<<" stack is empty "<<endl;
    }

    else if ((totalSize/2)+1 == st.size()){
    cout<<"Middle is "<< st.top();
    return;
    }
    //step no one
    int topElement = st.top();
    st.pop();
    
    //step two
    getMiddle(st,totalSize);
    
    //step three
    st.push(topElement);
}

void insertAtBottom(stack<int>& st, int item){
    // base case
    if(st.empty()) {
        st.push(item);
        return;
    }

    //step 1
    int topElement = st.top();
    st.pop();

    //step 2
    insertAtBottom(st,item);

    //step3 
    st.push(topElement);


}
void reverse (stack<int>& st) 
{
    //base case
    if(st.empty())
    return;


    //step 1
    int topElement = st.top();
    st.pop();

    // step 2
    reverse(st);


    //step3 
    insertAtBottom(st,topElement);

}

int main()
{
    stack<int>st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    
   // getMiddle(st,st.size());
   insertAtBottom(st,15);
   reverse(st);

   while(!st.empty()) {
    cout<<st.top()<<endl;
    st.pop();
   }
}
