#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    //create 
    unordered_map<char,int>m;

    string name = "babber";

   pair<char,int>p = make_pair('a',3);
    m.insert(p);

    m['b'] = 2;

    //m.insert({'c',5});

    //access

    cout<< m['b']<<endl;
    cout<< m['z']<<endl;

    cout<<m.size()<<endl;
    cout<<m.empty()<<endl;

    // present or not
    cout<<m.count('a')<<endl;
    cout<<m['j']<<endl;
    cout<<m.count('j')<<endl;


    unordered_map<char,int> :: iterator i = m.find('a');
    cout<<" value of itretar is "<<(*i).second<<endl;

    if(i != m.end()) {
        cout<< " element is found "<<endl;
    }
    else {
        cout<<" element is not found "<<endl;
    }

}