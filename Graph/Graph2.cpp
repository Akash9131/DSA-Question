#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph {
    public:
    map<int,list<pair<T,T> > >adjList;

    void addEdge(T u ,  T v, T weight, bool direction) {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // for u->v
        adjList[u].push_back(make_pair(v,weight));
        // check v->u
        if(direction == 0) {
            adjList[v].push_back(make_pair(u,weight));
        }
    }

    void printAdj() {
        for(auto i : adjList) {
            cout<<i.first <<"-> ";
            for(auto j : i.second) {
                cout<< " ( " <<j.first <<" , "<< j.second << " ), ";
            }
            cout<<endl;
        }
    }

    
};
int main() {
    Graph<int> g;
    g.addEdge(0,1,3,0);
    g.addEdge(1,2,4,0);
    g.addEdge(1,3,9,0);
    g.addEdge(2,3,8,0);
    g.addEdge(3,4,11,0);
    g.addEdge(2,4,10,0);

    cout<<" printing the adjancey list "<<endl;
    g.printAdj();


    


}