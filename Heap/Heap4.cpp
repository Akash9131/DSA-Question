// Merge k sorted array 
#include<iostream>
#include<queue>
using namespace std;

class Info {
    public:
    int data;
    int row;
    int col;

    Info(int d, int r, int c) {
        this->data = d;
       this-> row = r;
       this-> col = c;

    }

};

class Cmp {
    public:
    // dynamic chiye  static nhi  for  optmize storage
    bool operator()( Info* a, Info* b) {
        return a->data > b->data;

    }
    

};

vector<int>mergeKSortedArray(vector<vector<int> >arr, int k) {

    int n = arr[0].size();
    priority_queue<Info, vector<Info*>, Cmp > minHeap;
    vector<int>ans;
    
    // step1 :  put the first element  for all row into the heap
    for(int i =0; i<k; i++) {
        int element = arr[i][0]; 
        Info* temp = new Info(element,i,0);
        minHeap.push(temp);

    }
    while(minHeap.size()> 0 ) {
        // feach top element
        Info* temp = minHeap.top();
        minHeap.pop();

        // ans push
        ans.push_back(temp->data);

        // check  if next element is exist, if yes push in heap
        if(temp->col + 1 < n) {
            Info* toPush = new Info(arr[temp->row][temp->col + 1], temp->row, temp->col + 1);
            minHeap.push(toPush);
        }
    }
    return ans;
}
int smallestRangeKList(vector<vector<int> > arr, int k , int n) {
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<Info,vector<Info* >, Cmp > minHeap;
    //process first k element

    for(int i = 0; i< k; i++ ) {
        int element = arr[i][0];
        mini = min(mini, element);
        maxi = max(maxi,element);

        minHeap.push(new Info(element,i,0));
    }
    // for storing  answer range
    int start = mini;
    int end = maxi;

    while(!minHeap.empty()) {
        // extract top element or minimum element and pop from heap
        Info* temp = minHeap.top();
        minHeap.pop();

        // save data in mini
        mini = temp->data;

        // ans update
        if(end- start > maxi - mini) {
            end = maxi;
            start = mini;
        }


        // push next  element, and update maxi
        if(temp->col + 1 < arr[temp->row].size()) {
            Info* toPush = new Info(arr[temp->row][temp->col + 1], temp->row, temp->col + 1);
            minHeap.push(toPush);
            maxi = max(maxi,toPush->data);
        }
        else
        {
            break;
        }
    }
    cout<<"start : "<<start << " end : " <<end <<endl;
    return end- start;
}
int main()
{
   /*
    vector<vector<int> > arr(3, vector<int>(4,0));

    arr[0][0] = 1;
    arr[0][1] = 3;
    arr[0][2] = 5;
    arr[0][3] = 7;

    arr[1][0] = 2;
    arr[1][1] = 4;
    arr[1][2] = 6;
    arr[1][3] = 8;

    arr[2][0] = 0;
    arr[2][1] = 9;
    arr[2][2] = 10;
    arr[2][3] = 11;

    cout<<" Merge k sorted arrays is "<<endl;
    vector<int>ans = mergeKSortedArray(arr,3);

    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i] << " ";
    }
    cout<<endl;

    return 0;
    */
   vector<vector<int> > arr(3, vector<int>(4,0));

    arr[0][0] = 4;
    arr[0][1] = 10;
    arr[0][2] = 15;
    arr[0][3] = 24;
    arr[0][4] = 26;

    arr[1][0] = 0;
    arr[1][1] = 9;
    arr[1][2] = 12;
    arr[1][3] = 20;

    arr[2][0] = 5;
    arr[2][1] = 18;
    arr[2][2] = 22;
    arr[2][3] = 23;

   
    int ans = smallestRangeKList(arr,3,4);
     cout<<" smallest k range in list : "<< ans <<endl;

    


}