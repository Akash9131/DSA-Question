#include<iostream>
using namespace std;
int main()
{
    int n, m ;
    cin >>m >> n;
    int ** arr = new int*[m];

    for(int i=0; i<m; i++){
         arr[i] = new int[n];

    }

    //input
    for(int i= 0; i<m; i++){
        for(int j =0; j<n; j++){
            cin >> arr[i][j];
        }
    }

   cout<<" PRINT 2D ARR "<<endl;
    
    //input
    for(int i= 0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<< arr[i][j] <<" ";
        }
        cout<<endl;
    }

    //delete the 2d array
    for(int i=0; i<n; i++){
        delete []arr[i];

        delete []arr;
    }
}
