#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<vector>
#include<limits.h>
#include<set>
using namespace std;

template<typename T>
class Graph {
    public:
    map<T, list<pair < T,T> > > adjList;
    void addEdge(T u ,  T v, T wt, bool direction) {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // for u->v
        adjList[u].push_back(make_pair(v,wt));
        // check v->u
        if(direction == 0) {
            adjList[v].push_back(make_pair(u,wt));
        }
    }

    void printAdj() {
        for(auto i : adjList) {
            cout<<i.first <<"-> ";
            for(auto j : i.second) {
                cout<<"["<< j.first <<" , " << j.second<<"];";
            }
            cout<<endl;
       
        }
    }


    vector<int>Dijkstra(int src, int n) {
        vector<int>dist(n,INT_MAX);

        //distance , node
        set<pair<int,int> > st;

        // initial stap:
        dist[src] = 0;
        st.insert(make_pair(0,src));
        while(!st.empty()) {
            //step 1: get the top element
            auto top = *(st.begin());
            //pop
            st.erase(st.begin());

            int nodeDistance = top.first;
            int node =  top.second;

            // step: 2 explore neighbour 
            for(auto neighbour : adjList[node]) {
                // neighbour.first -> neighbour node name
                // neighbour.second -> neighbour weight
                
                if(nodeDistance + neighbour.second < dist[neighbour.first]) {
                    // remove old record
                    auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                    // if record  is found ,then erase it
                    if(record != st.end()) {
                        st.erase(record);
                    }

                    // distance update
                    dist[neighbour.first] = nodeDistance + neighbour.second;


                    // push new record
                    st.insert(make_pair(dist[neighbour.first],neighbour.first));
                }
            }
        }
        return dist;
    }
};
int main() {
    Graph<int>g;
     g.addEdge(0,1,5,0);
     g.addEdge(0,2,8,0);
     g.addEdge(1,2,9,0);
     g.addEdge(1,3,2,0);
     g.addEdge(2,3,6,0);

     g.printAdj();

    
     cout<<"sortest path in two vertice or Dijkstra algo : " <<endl;
     vector<int>ans = g.Dijkstra(0,4);
     for(auto  i : ans) {
        cout<< i<< " ";
     } cout <<endl;
}