#include<iostream>
using namespace std;

//class creation
class Human{
 
    
    //access modifier
    public:
   // data member
    int  age;
    char  gender;

    

    // default constructor

    //constructor
    Human(){
        cout<<"I am inside constructor ";
        cout<<endl;
        age = 11;
        gender = 'f';
    }

    //parametrize constructor
    Human(int age , int gender){
        cout<<" I am in Parameterize constructor  "<<endl;
        this->age = age;
         this->gender = gender; 
    }

    //copy constructor
    Human(Human& temp){
        cout<<"I am in copy constructor"<<endl;
       this->age = temp.age;
       this->gender = temp.gender;
    }

    //behavior
    int getAge(){
        return age;
    }
     
      void setAge(int a){
           age = a;
      }


     char getGender()
     {
        return gender;
     }


     void getGender( char ch)
     {
        gender = ch;
     }


// destructour
  ~Human(){
    cout<< "destructor called"<<endl;
  }
};
int main()
{
//     // object  creation
//     Human obj;

//     //access
//    cout <<obj.age<<endl;


//    //size og obj
//    cout<< sizeof(obj)<<endl;



//stack
 Human ramesh;
 ramesh.age = 121;
 cout<<ramesh.age<<endl;

 //dynamic
 Human *suresh = new Human();
 cout<< suresh->age << endl;


// parametrized constructor
Human *mukesh = new Human(18, 'M');
 cout<< mukesh->age << endl;
 cout<< mukesh->gender<<endl;

 //copy constructor
 Human jignesh(ramesh);
 cout<<jignesh.age<<endl;

 delete mukesh;
 delete suresh;
}