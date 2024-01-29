#include<iostream>
#include<Queue>
using namespace std;

int main()
{
    //creation
    queue<int>q;


    //push element
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(8);
    q.push(9);

    //remove element
    q.pop();
    

    // front element of queue
    cout<<"printing front element "<< q.front()<<endl;


    //rear element of queue
    cout<<"printing rear element "<<q.back()<<endl;

    // size
    cout<<"Size of Queue is  " << q.size()<<endl;

    //q is empty or not 
    cout<<"q is empty or not "<<q.empty()<<endl;

    cout<<"printing Queue : "<<endl;

    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;


}