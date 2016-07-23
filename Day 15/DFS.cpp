// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include <bits/stdc++.h>
#include <list>
#include <conio.h>
 
using namespace std;
 
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void DFS(int k);  // prints BFS traversal from a given source s
    void dfsutil(int k, bool visited[]);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 void Graph::dfsutil(int k, bool visited[]){
    visited[k]=true;
    cout<<k<<" ";
    list<int>::iterator i; 
    for(i=adj[k].begin();i!=adj[k].end();i++){
        if(!visited[*i])
            dfsutil(*i, visited);
    }
 }
 void Graph::DFS(int k){
    bool *visited= new bool[k];
    for(int i=0;i<k;i++)
        visited[i]=false;
    dfsutil(k, visited);
 }
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
    getch();
    return 0;
}