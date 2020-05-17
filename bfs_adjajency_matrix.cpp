#include<iostream>
#include<queue>
	
using namespace std;
class BFS
{
public:
	BFS(int size);
	void addEdge(int v, int w);
	void traverse(int s);
	int **matrix;
	bool *visited;
private:
	int size;
};
BFS::BFS(int size)
{
	this->size = size;
	visited = new bool[size];
	matrix = new int*[size];

	for(int i = 0; i<size; i++)
	{
		matrix[i] = new int[size];
	}
	for(int i =0 ;i<size; i++)
	{
		visited[i] = false;
	}

	for(int i = 0; i<size; i++)
	{
		for(int j = 0; j<size; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void BFS::addEdge(int v, int w)
{
	matrix[v][w] = 1;
	matrix[w][v] = 1;
}
void BFS::traverse(int s)
{
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while(!q.empty())
	{
		int v  = q.front();
		cout<<v<<" ";
		q.pop();
		for(int i = 0; i<size; i++)
		{
			if(matrix[v][i]==1&&visited[i]==false)
			{
				visited[i] = true;
				q.push(i);
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