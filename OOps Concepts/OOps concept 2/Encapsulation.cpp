#include<iostream>
using namespace std;

class Human{
    // Datamember
    private:
    int age;
    int weight;
    string name;


    public:
    int getAge()
    {
         return this->age;
    }
};
int main()
{
   Human obj;

// not accessable-> datamember  is private
//    obj.age;
//    obj.weight;
//    obj.name;

   obj.getAge();

}