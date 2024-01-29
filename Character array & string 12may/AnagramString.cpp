#include<iostream>
#include<map>
using namespace std;


bool checkAnagram(string a, string b){
  int freq[26] = {0};

  // increment count   for string a
  for(int i =0; i<a.length(); i++){
     char ch = a[i];
     int index =  ch - 'a';
     freq[index]++;
  }

   // decrement  count   for  string b
  for(int i =0; i<b.length(); i++){
     char ch = b[i];
     int index =  ch - 'a';
     freq[index]--;
  }

 

  for(int i=0; i<26; i++){
    if(freq[i] != 0)
    return false;
  }
  return true;
}

bool checkAnagramMapSol(string a, string b){
 map<char,int>m;

  // increment count   for string a
  for(int i =0; i<a.length(); i++){
     char ch = a[i];
     m[ch]++;
  }

   // decrement  count   for  string b
  for(int i =0; i<b.length(); i++){
     char ch = b[i];
      m[ch]--;
  }

  for(char i= 'a'; i< 'z'; i++){
    if(m[i] != 0)
    return false;
  }
  return true;
}
int main()
{
    string a = "babbar";
    string b = "raabbb";

    cout<<"ans is  anagram or not "<<checkAnagram(a,b)<<endl;

    string  c = "babbar";
    string  d = "repbbg";
    cout<<"ans in c d is  anagram or not "<<checkAnagram(c,d)<<endl;

    cout<<"ans is  anagram or not map Sol "<<checkAnagramMapSol(a,b)<<endl;
       cout<<"ans is  anagram or not map Sol "<<checkAnagramMapSol(a,d)<<endl;
}