#include<iostream>
#include<limits>
#include<list>
#include<vector>
using namespace std;
class Graph
{
public:
	void addEdge(int v, int w);
	void traverse(int v, int p, int discoveryCounter);
	Graph(int size);
	vector< pair<int,int> > result;
private:
	int *discovery;
	int *low;
	bool *visited;
	list<int> *adj;
	int size;
};
Graph::Graph(int size)
{
	this->size = size;
	adj = new list<int>[size];
	visited = new bool[size];
	low = new int[size];
	discovery = new int[size];

	for(int i = 0; i<size; i++)
	{
		visited[i] = false;
		discovery[i] = INT_MAX;
		low[i] = INT_MAX;
	}
}
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void Graph::traverse(int v, int p, int discoveryCounter)
{
	discovery[v] = discoveryCounter;
	low[v] = discoveryCounter;
	discoveryCounter++;
	visited[v] = true;
	list<int>::iterator it;
	for(it=adj[v].begin();it!=adj[v].end(); it++)
	{
		if(*it==p)
			continue;
		else if(visited[*it]==false)
		{
			traverse(*it,v,discoveryCounter);
			low[v] = min(low[v],low[*it]);
			if(discovery[v]<low[*it])
			{
				result.push_back(make_pair(v, *it));
			}
		}
		else 
		{
			low[v]=min(low[v],discovery[*it]);
		}
	}
}

int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.traverse(0,-1,0);
	pair<int, int> p = g.result[0]; // since we know 1 point is there hence hard coded. Otherwise use loop to taverse all points.
	cout<<p.first<<" "<<p.second;

	return 0;
}