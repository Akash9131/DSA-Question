#include<iostream>
using namespace std;

class Heap{
    public: 
    int arr[250];
    int size = 0;

    Heap() {
        size = 0;

    }

    void insertintoHeap(int val) {
        // we want to insert value
        size = size + 1;
        int index = size;

        //insert value
        arr[index] = val;

        //take value to its right position

        while(index > 1) {
            int parentIndex = index/2;

            if(arr[parentIndex] < arr[index]) {
            swap(arr[parentIndex],arr[index]);
            index = parentIndex;
            }
            else{
             break;
            }
        }
    }

    void print() {
        for(int i = 1; i<=size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap() {
        if(size == 0){
        cout<<" heap is already empty "<<endl;
        return;
        }


        // step 1:
        swap(arr[1],arr[size]);
        //step2:
        size --;

        //step 3 
        int index = 1;

        while( index <= size) {
            int largest = index;
            int left = 2*index;
            int right = 2*index + 1;

            if(left <= size && arr[left] > arr[largest]) {
                largest = left;
            }
            if(right <= size && arr[right] > arr[largest]) {
                largest = right;
            }

            if(largest != index) {
                swap(arr[index],arr[largest]);
            }
            else
            {
                // agar largest change hi nhi hua  to iska matlab tum curr pos 
                //par aa chuke ho
                break;
            }
        }
    }

};
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2* i ;
    int right = 2* i + 1;

    if(left <= n && arr[left]  > arr[largest]) {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]) {
        largest = right;

    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);

    }
}
int main()
{
    /*
    
    Heap maxheap;

    maxheap.insertintoHeap(2);
    maxheap.insertintoHeap(6);
    maxheap.insertintoHeap(8);
    maxheap.insertintoHeap(3);
    maxheap.insertintoHeap(7);

     cout<<"max heap is" << endl;
     maxheap.print();

     maxheap.deleteFromHeap();
     maxheap.print();

     maxheap.deleteFromHeap();
     maxheap.print();

     maxheap.deleteFromHeap();
     maxheap.print();

     maxheap.deleteFromHeap();
     maxheap.print();

     maxheap.deleteFromHeap();
     maxheap.print();

     maxheap.deleteFromHeap();
     maxheap.print();
     

*/
 int  arr[] = {-1,2,6,8,3,7};
 // logic for build heap

  int n = 5;
  for(int i = n/2; i>= 1; i--) {
    heapify(arr,n,i);
  }

  cout<<"printing after building Heap "<<endl;

  for(int i = 1; i<=n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
}