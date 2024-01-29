#include<iostream>
#include<string>
using namespace std;

int getLength(char arr[]){
    int length = 0;
    int index = 0;
    while(arr[index]  != '\0'){
        length++;
        index++;
    }
    return length;
}

void reverseString(char arr[]){
    //int n = strlen(arr);
    int n = getLength(arr);
    int start = 0;
    int end =  n-1;

    while(start<= end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
  
int main(){
    char name[10] = "LOVE";
    reverseString(name);
    cout<<"Reverse string is "<<name<<endl;
}