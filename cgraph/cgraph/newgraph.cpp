#include "newgraph.h"
void New_graph::print() {
	for (int i = 0; i < edges.size(); i++) 
	{
		if (edges[i].size()!=0)
			for (int j = 0; j < edges[i].size() -1; j+=2)
				cout << i << " -" << edges[i][j+1] << "- " << edges[i][j] << endl;
	}
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
bool New_graph::have_odd()
{
	for (int i = 0; i < edges.size(); i++)
	{
		if ((edges[i].size() / 2) % 2 != 0)
			return true;
	}
	return false;
}
bool New_graph::is_connected()
{
	vector<bool> visited;
	visited.resize(edges.size());
	for (int j = 0; j < edges.size(); j++)
		visited[j] = false;
	visited[0] = true;
	for (int j = 0; j < edges[0].size(); j += 2)
	{
		visited[edges[0][j]] = true;
	}
	for (int i = 1; i < edges.size(); i++)
	{
		bool flag = false;
		for (int j = 0; j < edges[0].size(); j += 2)
			if (visited[edges[i][j]])
				flag = true;
		if (flag)
			for (int j = 0; j < edges[i].size(); j += 2)
			{
				visited[edges[i][j]] = true;
			}
	}
	for (int i = 0; i < visited.size(); i++)
		if (!visited[i])
			return false;
	return true;
}
bool New_graph::euler_cycle()
{
	if (have_odd() || !is_connected())
		return false;
	else
		return true;
}