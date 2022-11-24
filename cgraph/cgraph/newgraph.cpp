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
int max(int a, int b)
{
	if (a > b)
		return a;
	else return b;
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
void New_graph::DFC(vector<bool>& visited, New_graph* &new_tree, int v)
{
	visited[v] = true;
	vector <int> el = edges[v];	
	for (int i = 0; i < el.size()-1; i+=2)
	{
		if (!visited[el[i]])
		{
			new_tree->add_edge(v, el[i], el[i + 1]);
			DFC(visited, new_tree, el[i]);
		}
	}
	
	/*list::iterator i;
	for (i = adjList.begin(); i != adjList.end(); ++i)
		if (!visited[*i])
			DFC(visited,*i);*/
}
int New_graph::get_size()
{
	return edges.size();
}
void New_graph::span_recprint(int node, int spaces)
{
	if (edges[node].size() != 0)
	{
		for (int i = 0; i < spaces; i++)
		{
			cout << "  ";
		}
		cout << node << endl;
		for (int i = 2; i < edges[node].size() -1; i+=2)
		{
			span_recprint(edges[node][i], spaces + 1);
		}
	}
}
void New_graph::spanning_print()
{
	cout << 0 << endl;
	for (int i = 0; i < edges[0].size() - 1; i+=2)
	{
		span_recprint(edges[0][i], 1);
	}
}