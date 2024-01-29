#include<iostream>
#include<limits.h>
using namespace std;

int reverse(int num) {
    int ans = 0;
    while(num != 0) {
        if(ans <(INT_MIN/10) || (ans > INT_MAX))
        {
            return 0;
        }
        int digit = num%10;
        ans = (ans*10) + digit;
        num = num/10;
    }
    return ans;


}
int main() {
    cout <<"Enter your number "<<endl;
    int num;

    cin >> num;

    cout<<"The reverse integer is "<<reverse(num)<<endl;

}