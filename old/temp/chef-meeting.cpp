// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include<iostream>
#include <list>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
 
using namespace std;

int path_length[5001][5001];
 
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v,int root, bool visited[],int last_dist);
public:
    Graph(int V);  // Constructor
    // int path_length[V][V];
    // int **path_length;
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
    void DFS(int v);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

    // cout<<"Hello 3"<<endl;

    /*
    path_length=new int*[V];
    for(int i=0;i++;i++)
    {
        path_length[i]=new int[V];
    }
    */

    // cout<<"size of path_length = "<<sizeof(path_length[0][0])<<endl;

    // cout<<"Hello adfdas1"<<endl;
    for(int i=0;i<V;i++)
    {
        // cout<<"YOYOYO"<<endl;
        path_length[1][1]=0;
        // cout<<"dfkjsjdfkasfjadsk"<<endl;
        for(int j=i+1;j<V;j++)
        {
            // cout<<" i and j are "<<i<<" "<<j<<endl;
            path_length[i][j]=0;
            path_length[j][i]=0;
            // path_length
        }
    }

    // cout<<"Hello drfas1"<<endl;

}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v);
}

void Graph::DFSUtil(int v,int root, bool visited[],int last_dist)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    // cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)

        if (!visited[*i])
            path_length[*i][root]+=last_dist;
            path_length[root][*i]+=last_dist;
            DFSUtil(*i,root, visited,path_length[root][*i]+last_dist);
}
 
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, v, visited,0);
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        // cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {

            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void printPath(int n)
{
    cout<<"path matrix : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<path_length[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        cout<<"Hello 2"<<endl;
        int n,m;
        scanf("%d %d",&n,&m);

        Graph g(n);
        int squares[m];

        cout<<"Hello 1"<<endl;

        for(int i=0;i<n;i++)
        {
            int x,y,temp;
            scanf("%d %d %d",&x,&y,&temp);
            g.addEdge(x-1,y-1);
            path_length[x-1][y-1]=path_length[y-1][x-1]=temp;
        }

        printPath(n);

        // cout<<"bro"<<endl;

        for(int i=0;i<m;i++)
        {
            scanf("%d",&(squares[i]));
        }
        // cout<<"yo bro"<<endl;

        g.DFS(squares[0]);


        /*
        for(int i=0;i<n;i++)
        {
            delete [] (g.path_length)[i];
        }
        delete [] g.path_length;
        */
    }
}