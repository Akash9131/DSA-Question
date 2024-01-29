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
int main(){
    //char array
   // char name[10];
    char lastName[10]= "AKKIRAJ";
    char lastName2[10]= "AKKIRAJ";
    
    //ip
   // cin >> name;

    //op
   // cout << name<<endl;

    cout<<"last name is "<<lastName<<endl;

   // cout<<"length is "<<getLength(lastName)<<endl;
     
    // cout<<"predefined fenction"<<strlen(lastName);
      // cout<<strcmp(lastName,lastName2);
}