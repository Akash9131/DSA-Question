#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n = 4;
    int i = 0;
    int ans = 0;

    while(n !=0){
        // bit nikal lo
        int bit = n & 1;

        ans = (bit * pow(10,i))+ans;
        // right shift kardo jisse most right bit lost/gum/ destroy ho jati hai
        n = n >> 1;
        i++;
    }
    cout<< "Decimal to Binary representation "<<ans <<endl;
}

// 100

