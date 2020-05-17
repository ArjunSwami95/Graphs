#include<iostream>

using namespace std;

class DFS
{
public:
	DFS(int size);
	void addEdge(int v, int w);
	void traverse(int s);
private:
	int **matrix;
	bool *visited;
	int size;
};
DFS::DFS(int size)
{
	this->size = size;
	matrix = new int*[size];
	for(int i = 0; i<size; i++)
	{
		matrix[i] = new int[size];
	}
	visited = new bool[size];
	for(int i = 0;i<size; i++)
		visited[i]=false;
}
void DFS::addEdge(int v, int w)
{
	matrix[v][w] = 1;
	matrix[w][v] = 1;
}

void DFS::traverse(int s)
{
	if(visited[s]==false)
	{
		cout<<s<<" ";
		visited[s] = true;
		for(int i = 0; i<size; i++)
		{
			if(matrix[s][i]==1)
				traverse(i);	
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
	
	dfs.traverse(0);
	return 0;
}