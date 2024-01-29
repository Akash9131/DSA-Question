#include<iostream>
using namespace std;

class Human{
    // Datamember
    public:
    int age;
    int weight;
    string name;


    public:
    int getAge(){
        return this->age;
    }


     void speak(){
        cout<<"Speaking "<<endl;
     }
};

class Female: public Human {
 void util(){
    cout<< this->age;
 }
};


class Math{
    public:
    int add (int a, int b){
        return a+ b;
    }
    
       int add (int a, int b, int c){
        return a+ b;
    }

       int add (int a, float b){
        return a+ b;
    }
    
};

int main()
{
    Female Akansha;

      Akansha.age;
      Akansha.speak();
}