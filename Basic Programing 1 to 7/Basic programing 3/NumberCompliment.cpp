#include<iostream>
using namespace std;
int compliment(int num) {
    int mask = 0;
     
     while(mask<num) {
        mask = (mask<<1) |1;

     }

     int ans = (~num) & mask;
     return ans;
}
int main() {
    cout<<" enter your number"<<endl;
    int num;
     cin >> num;


     cout<<"Numbercompliment is : "<<compliment(num)<<endl;

}