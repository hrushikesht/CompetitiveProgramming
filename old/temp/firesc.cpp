#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	vector< vector<int> > disjoint;
	void dfsUtil(int v,bool visited[],vector<int> x,bool color[]);
public:
	Graph(int v); //constructor
	void dfs(int v,vector<int> x,bool color[]);
	void addEdge(int v,int u);
	void adjList();
	vector< vector<int> > topologicalSort();
};

Graph::Graph(int v)
{
	// cout<<"machaya"<<endl;
	this->V=v;
	adj = new list<int>[V+1];
}

void Graph::addEdge(int v,int u)
{
	// cout<<"yo";
	adj[v].push_back(u);
}

void Graph::dfsUtil(int v,bool visited[],vector<int> x,bool color[])
{
	visited[v]=true;
	color[v]=true;
	// cout<<v<<" --> ";

	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		// cout<<" lol "<
		if(!visited[*i])
		{
			// cout<<*i<<" ";
			x.push_back(*i);
			dfsUtil(*i,visited,x,color);
		}
	}
}

void Graph::dfs(int v,vector<int> x,bool color[])
{
	// cout<<"Traversing for vertex "<<v<<endl;
	bool visited[V+1]={0};

	visited[v]=1;
	color[v]=1;

	// cout<<"paths for "<<v<<" are "<<endl;

	dfsUtil(v,visited,x,color);

	cout<<endl;
}

void Graph::adjList()
{
	cout<<"Adj List is"<<endl;
	for(int i=1;i<=V;i++)
	{
		cout<<i<<" : ";
		list<int>::iterator j;
		for(j=adj[i].begin();j!=adj[i].end();++j)
		{
			cout<<*j<<" ";
		}
		cout<<" / "<<endl;
	}
}

vector< vector<int> > Graph::topologicalSort()
{
	int i=1;
	while(i<=V)
	{

		bool color[V+1]={0};

		while(1)
		{
			if(color[i]==0)
			{
				break;
			}
			i++;
		}
		vector<int> x;
		disjoint.push_back(x);

		while(1)
		{
			dfs(i,x,color);
		}

	}
	return disjoint;
}

int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		int n,m;

		// cout<<"enter number vertices and edges";
		cin>>n>>m;

		Graph g(n);

		// cout<<"enter the edges"<<n<<"  "<<m<<endl;

		// cout<<"doing for case "<<test<<endl;
		
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;

			g.addEdge(x,y);
			// g.addEdge(y,x);
		}

		g.adjList();

		/*for(int i=1;i<=n;i++)
		{
			cout<<"dfs for vertex "<<i<<endl;
			g.dfs(i);
			cout<<endl;
		}
		cout<<endl;*/

		vector< vector<int> > disjoint=g.topologicalSort();

		vector< vector<int> >::iterator i;
		vector<int>::iterator j;
		// int i=0,j=0;

		for(i=disjoint.begin();i!=disjoint.end();++i)
		{
			cout<<"sort is"<<endl;
			for(j=i->begin();j!=i->end();++j)
			{
				cout<<" hi "<<*j;
			}
			cout<<endl;
		}
	}
}

