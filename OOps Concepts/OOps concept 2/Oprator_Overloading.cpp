#include<iostream>
using namespace std;

class  Demo {
    public:
    int first;
    int second;
    static int total;

   // binary operator
    Demo operator+ (Demo&  temp){
          Demo result;
          result.first = this->first + temp.first;
          result.second = this->second + temp.second;
          return result;
    }


    // unary operator
    void operator ++(){
        cout<<"unary operator overloaded "<<endl;
    }
};

// Human
class Human{
   public:
   int legs  = 2;
   int hands  = 2;
};
void operator <<(ostream& os, Human& Akash){
    cout<<Akash.legs<<" ";
    cout<<Akash.hands<<" " <<endl;
}

// <<
void operator <<(ostream& os, Demo& obj){
    cout<<obj.first<<" ";
    cout<<obj.second<<" " <<endl;
}

//Difination of static variables
int Demo::total = 0;
int main()
{
    //    Demo a;
    //    Demo b;

    // //    a+b;
         // binary oerator
    //    Demo c = a + b;

// unary operator
    //    ++a;

    Demo obj;

    cout<<obj;
    cout<<obj.total<<endl;
    cout<<Demo::total<<endl;


    Human Akash;
    cout<<Akash;
      
}