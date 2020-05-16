#include<iostream>
#include<list>
#include<queue>

using namespace std;
class BFS
{
public:
	BFS(int size);
	void addEdge(int v, int w);
	void traverse(int s);
private:
	list<int> *adj;
	bool*visited;
	int size;
};
BFS::BFS(int size)
{
	this->size = size;
	visited = new bool[size];

	adj = new list<int>[size];

	for(int i = 0; i<size; i++)
		visited[i] = false;
}
void BFS::addEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void BFS::traverse(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;

	list<int>::iterator it;

	while(!q.empty())
	{
		int v = q.front();
		cout<<v<<" ";
		q.pop();
		for(it=adj[v].begin(); it!=adj[v].end(); it++)
		{
			if(visited[*it]==false)
			{
				visited[*it]=true;
				q.push(*it);
			}
		}
	}
}
int main()
{
	BFS bfs(5);
	bfs.addEdge(0,1);
	bfs.addEdge(0,2);
	bfs.addEdge(1,2);
	bfs.addEdge(1,3);
	bfs.addEdge(2,3);
	bfs.addEdge(2,4);
	bfs.addEdge(3,4);
	
	bfs.traverse(0); //starting point

	return 0;
}