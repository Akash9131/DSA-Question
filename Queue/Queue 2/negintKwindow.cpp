// find negative integerin a every window in k size
#include<iostream>
#include<Stack>
# include<Queue>
#include<vector>
using namespace std;

void solve(vector<int>& v, vector<int>& ans, int k)
{
    //step 1: queue creation
    queue<int> q;

    // step 2: first window process
    for(int i= 0; i<=k; i++) {
        //neg int hai to push kar do
        if(v[i] < 0)
        q.push(i);
    }

    //step 3: ans save

    if(q.size() > 0)
    ans.push_back(v[q.front()]);
    else 
    ans.push_back(0);

    // step 4: remaining window process
    for( int i = k; i<v.size(); i++) {
        //condition true hai to pop kar do
        if(!q.empty() && i - q.front() >= k) {
            q.pop();
        }
        //push in queue
        if(v[i] <0)
        q.push(i);
          
          //ans store
        if(q.empty())
        ans.push_back(0);
        else
        ans.push_back(v[q.front()]);

    }
}
int main()
{
    vector<int> v;
    v.push_back(-8);
    v.push_back(2);
    v.push_back(3);
    v.push_back(-6);
    v.push_back(10);

    vector<int>ans;
    solve(v,ans,2);


    cout<<"printing the ans "<<endl;

    for(int i= 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout <<endl;


}