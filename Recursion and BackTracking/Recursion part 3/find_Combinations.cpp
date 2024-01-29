#include<iostream>
using namespace std;
void findCombinations(string input, int i , string output){
    // base case
    if( i == input.length()){
     cout<< output <<endl;
     return;
    }

    
    char ch = input[i];
     // no space - put character without space
     output.push_back(ch);
     findCombinations(input,i+1,output);

     //with space - put charter with space
     output.push_back(' ');

     if(input[i+1] != '\0')
     findCombinations(input,i+1,output);

}

int main()
{
    string str = "123";
    string output = "";
    int index = 0;
    findCombinations(str,index,output);
}