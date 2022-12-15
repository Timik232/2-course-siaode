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
bool New_graph::is_safe(int v, vector <int>path, int pos)
{
	if (edges[path[pos - 1]][v] == 0)
		return false;
	for (int i = 0; i < pos; i++)
		if (path[i] == v)
			return false;
	return true;
}
bool New_graph::find_Hamcycle(vector <bool> visited, vector <int> path, int pos)
{
	if (pos == edges.size()-1)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i];
		}
		cout << endl << endl;
		if (edges[path[path.size() - 1]][0] != 0)
		{
			path.push_back(0);
			all_hamilt.push_back(path);
			return true;
		}
		
	}
	for (int i = 0; i < edges.size(); i++)
	{
		if (is_safe(i, path, pos))
		{
			path.push_back(i);
			visited[i] = true;
			find_Hamcycle(visited, path, pos + 1);
			visited[i] = false;
			path.pop_back();
		}
	}
}
vector <vector <int>> New_graph::all_hamiltonian()
{
	vector <bool> visited;
	for (int i = 0; i < edges.size(); i++)
	{
		visited.push_back(false);
	}
	visited[0] = true;
	vector <int> path;	
	//path.resize(edges.size());
	path.push_back(0);
	bool has_cycle = find_Hamcycle(visited, path, 1);
	if (!has_cycle) {
		cout << "Can't find Hamiltonian Cycle\n";
	}
	return all_hamilt;
}