#include<iostream>
//#include<stack>
using namespace std;

class Stack{
    public:

    int *arr;
    int top;
    int size;

    Stack(int size){
        arr = new int[size];
        top = -1;
        this->size = size;
    }

    void push( int data)
    {
        // first check if array is full
        if(top == size-1){
            cout<<"stack overflow for element  "<<data<<endl;
            return;
        }
        top++;
        arr[top] = data;
        cout <<"Top -> "<<top<<endl;
        cout<<"arr[top] -> "<<arr[top]<<endl;
    }

    void pop(){
        //check if array is empty or not
        if(top == -1) {
            cout<<" stack is underflow "<<endl;
            return;
        }
        top--;

    }
    bool stackEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    int  getSize(){
        // it is return  the number of element present in stack
        return this->top+1;
    }

    

    int gettop(){
        if(top != -1)
        return arr[top];
        else
        return true;
    }
};
int main()
{
   /*
    // creation of stack
    stack<int>st;

     // insertion
    st.push(5);
    st.push(7);
    st.push(9);
    
    //check size
    cout<<"size is "<<st.size()<<endl;

    //check empty or not
    cout<<"empty or not "<<st.empty() <<endl;


    // remove
    st.pop();


    // top element
    cout<<"top element "<< st.top()<<endl;
    */

    // create stack with size = 10
    Stack* st = new Stack(10);

    st->push(3);
    st->push(4);
    st->push(6);
    st->push(8);
    st->push(9);
    st->push(11);
    st->push(12);
    st->push(13);
    st->push(14);
    st->push(15);

    
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->pop();

   cout<< st->getSize()<<endl;
  // cout<<st->isEmpty()<<endl;

    

}