#include<iostream>
using namespace std;

bool findin_rotatedString(string a, string b){
    if(a.length() != b.length())
    return false;

    string temp = a + a;

    if(temp.find(b) == noshowpos(b))
    return false;
    else
    return true;
        
   
}
int main()
{
    string a = "bbarba";
    string b = "babbar";
}