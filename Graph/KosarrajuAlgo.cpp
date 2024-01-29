#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

template<typename T>
class Graph {
    public:
    map<T, list<T>> adjList;
    void addEdge(T u ,  T v, bool direction) {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // for u->v
        adjList[u].push_back(v);
        // check v->u
        if(direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void printAdj() {
        for(auto i : adjList) {
            cout<<i.first <<"-> ";
            for(auto j : i.second) {
                cout<<j<<"; ";
            }
            cout<<endl;
        }
    }
    void dfs(stack<int>& st, map<int,bool>& vis, int node) {
        vis[node] = true;
        for(auto neighbour : adjList[node]) {
            if(!vis[neighbour]) {
                dfs(st,vis,neighbour);
            }
        }
        st.push(node);
    }

    void transpose(map<int,list<int> >& newAdjList) {
        for(auto i : adjList) {
            int u = i.first;
            for(auto v : i.second) {
                newAdjList[v].push_back(u);
            }
        }
    }

    void revDfs(map<int,bool>& vis, int node, map<int,list<int>> & newAdjList) {
        cout<<node<< " ,";
        vis[node] = true;
        for(auto neighbour : newAdjList[node]) {
            if(!vis[neighbour]) {
                revDfs(vis,neighbour,newAdjList);
            }
        }
    }
};

int main() {
    Graph<int>g;

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,0,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);

g.printAdj();

// step 1: topo Ordering
 stack<int>st;
 map<int,bool>vis;

 int n = 5;
 for(int i =0; i<n; i++) {
    if(!vis[i])  {
        g.dfs(st,vis,i);
    }
    
 }

 // step 2: transpose graph -> u->v se v->u
 map<int,list<int>>newAdjlist;
 g.transpose(newAdjlist);

 //step 3 : dfs basis on Topoligical sort
 int count = 0;
 map<int,bool>vis2;

 while(!st.empty()) {
    int node = st.top();
    st.pop();
     if(!vis2[node]) {
        count ++;
        g.revDfs(vis2,node,newAdjlist);
        cout<<endl;
    }
 }
 

cout<<" Total SCC are : " <<count<<endl;


}