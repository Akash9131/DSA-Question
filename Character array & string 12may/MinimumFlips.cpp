#include<iostream>
using namespace std;

char flip(char expected){
    if(expected == '0')
    return '1';
    else
    return '0';
}

int getFlips(string str, char expected){
    int countFlips =  0;

    for(int i=0; i<str.length();i++){
        if(str[i] != expected)
            countFlips++;
            expected = flip(expected);
    }
    return countFlips;
}
int main()
{
    string str ="0010";
    // if ans start with 0
    int ans0 = getFlips(str,'0');
    //if ans start with 1
    int ans1 = getFlips(str,'1');

    int ans  = min(ans0,ans1);

    cout<<" minimum no of flips in string "<< ans <<endl;
}