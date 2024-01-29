#include<iostream>
#include<Stack>
#include<vector>
using namespace std;

bool Knows(int a, int b, int arr[4][4]) {
    return arr[a][b];
}


int findCelebrity(int arr[4][4], int n) {
    stack<int>s;
    // push all elements in the stack
    for(int i= 0; i<n; i++) {
        s.push(i);
    }

    //find candidate(for celebrity)
    while(s.size() > 1)
    {
        int first = s.top();
        s.pop();

        int second = s.top();
        s.pop();

        if(Knows(first,second,arr))
            s.push(second);
        else
            s.push(first);
    }
    
    //store candidate
    int candidate = s.top();
    s.pop();


    //verifification for candidate
    // check row for all 0"s
    bool checkRow = true;

    for(int i = 0; i<n; i++) {
        if(arr[candidate][i] == 1) {
            checkRow = false;
            break;
        }
    }

    // check column for all 1"s except  row == col wala case
    bool checkCol = true;
    for(int i= 0; i<n;i++) {
        if( i != candidate && arr[i][candidate] == 0) {
            checkCol = false;
            break;
        }
    }
    
    //if verification succeds, candiate are celibreties 
    if(checkRow && checkCol)
    return candidate;

    
}

int main()
{
    int arr[4][4] ={{0,0,1,0},{0,0,1,0},{0,0,0,0},{0,0,1,0}};

    cout<<"celabrity is "<<findCelebrity(arr,4)<<endl;
}