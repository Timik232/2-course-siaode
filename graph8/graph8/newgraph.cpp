#include "newgraph.h"
#include <list>
void New_graph::print() {
	for (int i = 0; i < edges.size(); i++) 
	{
		if (edges[i].size()!=0)
			for (int j = 0; j < edges[i].size() -1; j+=2)
				cout << i << " -" << edges[i][j+1] << "- " << edges[i][j] << endl;
	}
}
bool New_graph::have_edge(int val1, int val2, vector <bool> &visited)
{
	bool flag = false;
	for (int i = 0; i < edges.size(); i++)
	{
		if (visited[i])
		{
			for (int j = 0; j < edges[i].size() - 1; j += 2)
			{
				if (visited[edges[i][j]])
					return true;
			}
		}
		else if (!visited[i])
		for (int j = 0; j < edges[i].size() - 1; j += 2)
		{
			if (visited[edges[i][j]])
				return false;
		}
	}
	return false;
}
void New_graph::add_edge(int src, int target, int length)
{
	int more = max(src, target);
	if (edges.size() < more + 1)
		edges.resize(more + 1);
	edges[src].push_back(target);
	edges[src].push_back(length);
	edges[target].push_back(src);
	edges[target].push_back(length);
}


int New_graph::get_size()
{
	return edges.size();
}
bool New_graph::have_hamiltonian()
{
	for (int i = 0; i < edges.size(); i++)
	{
		int amount = edges[i].size() / 2;
		if (amount < 2)
			return false;
	}
	return true;
}