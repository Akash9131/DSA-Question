#include<iostream>
using namespace std;

void printPowerSet(string input, int index, string output)
{
    // base case
    if(index == input.length())
    {
    cout<<output <<endl;
    return;
    }

    char ch = input[index];

    //exclude ch
    printPowerSet(input, index+1, output);

    //include ch
    output.push_back(ch);
    printPowerSet(input, index+1, output);

  
}
int main()
{
    string str;
    cout<<"entter the string "<<endl;

    cin>> str;

    string output = "";

    printPowerSet(str,0,output);
}