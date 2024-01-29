#include<iostream>
#include<Queue>
using namespace std;

class CircularQueue {

    public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int s) {
        arr = new int[s];
        front = rear = -1;
        size = s;
    }
    

        void Enqueue(int element) {
            // overflow
            if((front == 0 && rear == size-1) || (rear ==(front - 1)% size))
            {
                cout<<" overflow ho gya "<<endl;
                return;
            }
            else if(front == -1){
                //first element insertation
                front = rear = 0;
            }
            else if( rear == size -1 && front != 0) {
                // handle circular insertion case
                rear = 0;
            }
            else{
                // normal insertion case ->no cornar case
                rear++;
            }
            arr[rear] = element;
        }

        void Dequeue() {
            //overflow
            if(front == -1) {
                cout<<"underflow ho gya "<<endl;
                return;
            }
            else if( front == rear) {
                // single element

                front = rear = -1;
            }
            else if(front == size-1) {
                //circular nature
                front = 0;
            }
            else{
                //normal case
                front ++;
            }
        }

        bool isEmpty()
        {
            if(front == -1) {
                return true;
            }
            else
            return false;
        }

        int getFront() {
            if(front == -1)
            return -1;
            else
                return arr[front];
            
        }
    

};
int main()
{

    CircularQueue* q = new CircularQueue(5);
    q->Enqueue(3);
    q->Enqueue(5);
    q->Enqueue(7);
    q->Enqueue(9);
    q->Enqueue(11);


    cout<<"Front element "<<q->getFront()<<endl;

    q->Dequeue();
    cout<<"Front element is "<<q->getFront()<<endl;
    q->Enqueue(13);
    q->Dequeue();
    q->Dequeue();
    q->Enqueue(14);
    q->Enqueue(15);
    cout<<"Front element is "<<q->getFront()<<endl;

    while(!q->isEmpty()) {
        cout<< q->getFront()<<" ";
        q->Dequeue();

    }
    cout<<endl;


}