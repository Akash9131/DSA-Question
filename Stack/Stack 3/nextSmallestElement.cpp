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

      while(s.top() >= item)
      {s.pop();
      }
      ans[i] = s.top();
      s.push(item);
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

      while(s.top() >= item)
      {s.pop();
      }
      ans[i] = s.top();
      s.push(item);
    }
    return ans;
}

int main()
{
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);


    vector<int>ans = nextSmaller(arr);
    vector<int>ans1 = prevSmaller(arr);


    cout<<"next smaller element is "<<endl;
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


  cout<<"prev smaller element is "<<endl;
    for(int i = 0; i<ans1.size(); i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;


}
