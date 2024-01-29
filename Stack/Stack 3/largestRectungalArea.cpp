//Largest rectungular area in histogram

 #include<iostream>
#include<Stack>
#include<vector>
using namespace std;

vector<int>nextSmaller(vector<int> arr) {
    stack<int>s;
    s.push(-1);

    int n = arr.size();
    vector<int>ans(n);

    for(int i= n-1; i >= 0; i--)
    {
      int item = arr[i];

      while(s.top() != -1  && arr[s.top()] >= item) {
        s.pop();
      }

      if(s.top() == -1) 
        ans[i] = n;
      else
        ans[i] = s.top();

      s.push(i);
    }
    return ans;
}

vector<int>prevSmaller(vector<int> arr) {
    stack<int>s;
    s.push(-1);

    int n = arr.size();
    vector<int>ans(n);

    for(int i= 0; i <= n-1; i++)
    {
      int item = arr[i];

      while(s.top() != -1 && arr[s.top()] >= item)
      {s.pop();
      }
      ans[i] = s.top();
      s.push(i);
    }
    return ans;
}


int LargestArea(vector<int>arr) 
{
    vector<int>next = nextSmaller(arr);
    vector<int>prev = prevSmaller(arr);
    

    int maxArea = INT_MIN;

    for(int i= 0; i<arr.size(); i++)
    {
        int length = arr[i];
        int breath = next[i]-prev[i] -1;
        int newArea = length * breath;
         maxArea = max(maxArea, newArea);
    }
    return maxArea;

}



int main()
{
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);


    vector<int>prev =prevSmaller(arr);
    vector<int>next = nextSmaller(arr);
  
    cout <<"prev smaller  element is "<<endl;
    for(int i=0; i<prev.size(); i++) {
        cout<<prev[i]<<" ";
    }
    cout<<endl;

    cout <<"next smaller  element is "<<endl;
    for(int i=0; i<next.size(); i++) {
        cout<<next[i]<<" ";
    }
    cout<<endl;

cout<<"Max area is " << LargestArea(arr)<<endl;

}