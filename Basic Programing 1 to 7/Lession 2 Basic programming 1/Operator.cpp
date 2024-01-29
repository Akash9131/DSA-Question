#include<iostream>
using namespace std;
int main()
{
   /*
    int a,b,c;
    cout<<"Enter the number of a and b and c "<<endl;
    cin >> a >> b >> c;

  // logical  opreator
  int ans = a+b;
  int ans1 = a-b;
  int ans2 = a*b;
  int ans3 = a/b;
  cout << " ans is "<< ans<<endl;
  cout << " ans is "<< ans1<<endl;
  cout << " ans is "<< ans2<<endl;
  cout << " ans is "<< ans3<<endl;
  

 // Relational opratar
 if(a>b){
     cout<<"a is greater then b "<<endl;
 }
 else if(a<b){
     cout <<"  a is less then b " <<endl;
 }
 else if(a== b){
     cout<< " a and b is equal "<<endl;
 }

 
 if(a>=b){
     cout << "a and b is equal or a is greater then b "<<endl;
 }
 else if(a<=b){
      cout << "a and b is equal or a is less then b "<<endl;
 }

 
 if(a!= b){
     cout<<" a and b is not equal "<<endl;
 }



//logical operators

bool ans = (a==b) && (b==c) && (c== a);
cout<< "this is  and and opratar  "<<ans << endl; // 0 means false  and 1 is true

bool ans1 = (a==b) || (b==c) || (c== a);
cout<< "this is  OR OR opratar  "<<ans1 << endl;

bool ans2 = (a+b) != (b+c);
cout<< " rhis is not equal oprator "<< ans2 <<endl;
*/

/*
// Bitwise oprator
int num1, num2;
cin >> num1 >> num2;

int ansa = num1&num2;
cout<<"This is and oprator "<<ansa<<endl;

int anss = num1|num2;
cout<<"This is or oprator "<<anss<<endl;

int ansd = ~num2;
cout<<"This is not oprator "<<ansd<<endl;

int ansf = num1^num2;
cout<<" This is Xor oprator "<<ansf<<endl;
*/

// left shift operator;

int n = 5;
int m = -5;


cout<<" left shift oprator  for 5  :-> " << (5<<1 )<<endl;
cout<< " left shift oprator  for 5 :-> "<<(5<<2 )<<endl;
cout<< " left shift oprator  for 5 :-> "<<(-5<<1 )<<endl;
cout<< " left shift oprator  for 5 :-> "<<(-5<<2 )<<endl;


cout<<" right shift oprator  for 5 :-> " << (5>>1 )<<endl;
cout<<" right shift oprator  for 5 :-> " << (5>>2 )<<endl;
cout<<" right shift oprator  for 5 :-> " << (-5>>1 )<<endl;
cout<<" right shift oprator  for 5 :-> " << (-5>>2 )<<endl;



}