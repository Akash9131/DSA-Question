#include<iostream>
#include<Queue>
#include<Stack>
using namespace std;

void reverse(queue<int>& q) {
    // base case
    if(q.empty())
    return;

    int element = q.front();
    q.pop();
    reverse(q);
    q.push(element);
}
int main()
{
    queue<int> q;
    q.push(2);
    q.push(5);
    q.push(7);
    q.push(8);
    q.push(9);


    /*

    //step1 : queue ko stack me dalo
    stack<int> s;

    while(!q.empty()){
        int element = q.front();
        q.pop();

        s.push(element);
    }

    // step 2: stack ko queue me dalo
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);

    }
    */
   reverse(q);
    cout<<"printing the queue "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();

    }
    cout<<endl;

}