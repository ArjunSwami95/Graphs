#include<iostream>
#include<list>

using namespace std;
class DFS
{
public:
	DFS(int size);
	void addEdge(int v, int w);
	void traverse(int s);
private:
	int size;
	list<int> *adj;
	bool* visited;
};
DFS::DFS(int size)
{
	this->size = size;

	adj = new list<int>[size];
	visited = new bool[size];
	
	for(int i = 0;i<size; i++)
	{
		visited[i] = false;
	}

}
void DFS::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void DFS::traverse(int v)
{
	if(visited[v]==false)
	{
		cout<<v<<" ";
		visited[v] = true;
		list<int>::iterator it;
		for(it=adj[v].begin(); it!=adj[v].end(); it++)
		{
			traverse(*it);
		}
	}	
}
int main()
{
	DFS dfs(5);
	dfs.addEdge(0,1);
	dfs.addEdge(0,2);
	dfs.addEdge(1,2);
	dfs.addEdge(1,3);
	dfs.addEdge(2,3);
	dfs.addEdge(2,4);
	dfs.addEdge(3,4);
	
	dfs.traverse(0); //starting point
	return 0;
}