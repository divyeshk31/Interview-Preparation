#include <iostream>
#include <string.h>
#include <vector>
#include <conio.h>
using namespace std;

class Graph
{
private:
    int v;
    vector<int>* adj;
    bool isCyclicUtil(int s,bool visited[],int parent);
public:
    Graph(int V);
    void addEdge(int s,int d);
    bool isCyclic();
};

Graph::Graph(int V)
{
    v=V;
    adj=new vector<int>[V];
}

void Graph::addEdge(int s,int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

bool Graph::isCyclicUtil(int s,bool visited[],int parent)
{
    visited[s]=true;

    for(int i=0;i<adj[s].size();i++)
    {
        int temp=adj[s][i];
        if(!visited[temp])
        {
            if(isCyclicUtil(temp,visited,s))
                return true;
        }
        else if(temp!=parent)
            return true;
    }
    return false;
}

bool Graph::isCyclic()
{
    bool visited[v];
    memset(visited,false,sizeof(visited));

    for(int i=0;i<v;i++)
        if(!visited[i])
            if(isCyclicUtil(i,visited,-1))
                return true;

    return false;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";


    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
    getch();
    
    return 0;
}
