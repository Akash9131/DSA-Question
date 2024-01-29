#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class Graph {
    public:
    map<int,list<int> > adjList;
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
                cout<< j <<" , ";
            }
            cout<<endl;
        }
    }

     void bfs(int src, map<int,bool> &visited) {
        queue<int> q;
        q.push(src);

       // map<int,bool> visited;
        visited[src] =  true;

        while(!q.empty()) {
            int front = q.front();
            cout << front << ", ";
            q.pop();

            for(auto neighbour: adjList[front]) {
                if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    
    void dfs(int src, map<int,bool>& visited) {
        visited[src] = true;
        cout<<src<<" , ";

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour]) {
                dfs(neighbour,visited);
            }
        }
    }

    bool isCyclicBFS(int src) {
        map<int,bool>visited;
        map<int,int>parent;
        queue<int > q;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for(auto  neighbour : adjList[front]) {
                if(visited[neighbour] == true && neighbour != parent[front]) {
                    return true;
                }
                else if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }

        }
        return false;

    }

    bool isCyclicDFS(int src,int parent , map<int,bool>& visted) {
        visted[src] = true;

        for(auto  neighbour : adjList[src]) {
            if(!visted[neighbour]) {
                bool cycleDetect = isCyclicDFS(neighbour, src, visted);
                if(cycleDetect == true)
                return true;
            }
            else if(visted[neighbour] == true && neighbour != parent) {
                // cycle present
                return true;

            }
        }
        return false;
    }

    // directed graph 

    bool isCyclicDFSDirected(int src, map<int,bool>& visited, map<int,bool>& dfsVisited) {
        visited[src] = true;
        dfsVisited[src] = true;

        for(auto neighbour : adjList[src]) {
            if(!visited[neighbour]) {
                bool cyclicDetect = isCyclicDFSDirected(neighbour,visited,dfsVisited);
                if(cyclicDetect == true) 
                {
                    return true;
                }
            }
            else if(visited[neighbour] == true && dfsVisited[neighbour] == true)  {
                return true;
            }
        }
        // back track
        dfsVisited[src] = false;
        return false;
    } 

    void topoLogicalSort() {
        // step 1: find out  all indegree
       unordered_map<int,int> Indgree;
        queue<int>q;

        // initalse indgree with 0
        for(auto i : adjList) {
            Indgree[i.first] = 0;
        }

        for(auto i : adjList) {
            for(auto j : i.second) {
                Indgree[j]++;
            }
        }
         // step 2 :push in queue, indgree-> 0
         for(auto i : Indgree) {
            if(i.second == 0) {
                q.push(i.first);
            }
         } 

         // step 3: BFS
         while(!q.empty()) {
            int front = q.front();
            cout << front <<" ";
            q.pop();

            for(auto neighbour : adjList[front]) {
                Indgree[neighbour]--;
                if(Indgree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
         }
    }

       

      void sortestPathUDG(int src, int distination) {
        map<int,bool>visited;
        map<int,int>parent;
        queue<int > q;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for(auto  neighbour : adjList[front]) {
                    if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }

        }

        // preaper sortest path in undirected graph using dijkastra algo
        vector<int>ans;
           
        ans.push_back(distination);
        while(parent[distination] != src) {
            ans.push_back(parent[distination]);
        }
        ans.push_back(src);

        reverse(ans.begin(),ans.end());
        return ans;




    }
};
int main() {
    Graph<int> g;
    // component 1 c1
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(2,4,0);

    //componet2 c2
    g.addEdge(5,6,0);

    cout<<" printing the adjancey list "<<endl;
    g.printAdj();



cout<<" printing the bfs traversal "<<endl;
    int n = 7;
    // to handle graph with disconnected component
     map<int,bool> visited;
    for(int i= 0; i<n; i++) {
        if(!visited[i]) {
            g.bfs(i,visited);
        }
    }
    cout<<endl;

    cout<<" loop present or not "<< g.isCyclicBFS(0)<<endl;
    cout<<endl;


int parent = -1;
map<int,bool>visited3;
 cout<<" loop present or not  by  DFS "<< g.isCyclicDFS(0,parent,visited3)<<endl;
    cout<<endl;



Graph<int>g2;
g2.addEdge(0,2,0);
g2.addEdge(2,3,0);
g2.addEdge(2,4,0);
g2.addEdge(3,4,0);
g2.addEdge(1,3,0);

cout<<" printing the adjancey list "<<endl;
    g2.printAdj();

cout << " printing dfs traversal "<<endl;

    // to handle graph with disconnected component
     map<int,bool>visited2;
     for(int i = 0; i<5; i++) {
        g2.dfs(i,visited);
     }
     cout<<endl;

     for(int i = 0; i<5; i++) {
        if(!visited[i]) {
            bool ans = g2.isCyclicBFS(i);

            if(ans == true) {
                return true;
            }
            else {
                return false;
            }

        }
     }
     cout<<" loop present or not "<< g2.isCyclicBFS(0)<<endl;
   cout<<endl;


// disconnected graph ke liya
   int parent1 = -1;
map<int,bool>visited4;
for(int i = 0; i<3; i++) {
        if(!visited[i]) {
            bool ans = g2.isCyclicDFS(i,parent1,visited4);

            if(ans == true) {
                return true;
            }
            else {
                return false;
            }

        }
     }
     // connected graph ke liye
 cout<<" loop present or not  by  DFS "<< g2.isCyclicDFS(0,parent,visited4)<<endl;
    cout<<endl;



    Graph<int>g4;
    g4.addEdge(1,2,1);
    g4.addEdge(2,3,1);
    g4.addEdge(2,4,1);
    g4.addEdge(3,7,1);
    g4.addEdge(3,8,1);
    g4.addEdge(4,5,1);
    g4.addEdge(5,6,1);
   // g4.addEdge(6,4,1);
    g4.addEdge(8,7,1);

    cout<< "print the adj List"<<endl;
    g4.printAdj();

    map<int,bool>visited5;
    map<int,bool>dfsVis;
    cout<<" Cycle is present or not Directed graph using dfs :  "<<g4.isCyclicDFSDirected(1,visited5,dfsVis)<<endl;



    Graph<int>g5;
    g5.addEdge(1,2,1);
    g5.addEdge(1,3,1);
    g5.addEdge(2,5,1);
    g5.addEdge(3,5,1);
    g5.addEdge(5,4,1);

    cout<<"printint the diracted acyclic graph "<<endl;
    g5.printAdj();
    cout<<endl;
    cout<<" printing the topoLogical Sort :  "<<endl;
    g5.topoLogicalSort();


    Graph<int>g6;
    g6.addEdge(1,2,0);
    g6.addEdge(1,4,0);
    g6.addEdge(1,3,0);
    g6.addEdge(2,5,0);
    g6.addEdge(4,6,0);
    g6.addEdge(5,8,0);
    g6.addEdge(3,8,0);
    g6.addEdge(6,7,0);
    g6.addEdge(7,8,0);

    cout<<"printing the  adj list"<<endl;
    g6.printAdj();

    cout<<"sortest path in undirected graph :"<<endl;
    g6.sortestPathUDG(1,8);



}