#include "graph.h"
#include <iostream>
using namespace std;
Graph::Graph(string value)
{
	this->value = value;
}
Graph::~Graph()
{
	for (int i = 0; i < pointers.size(); i++)
	{
		delete pointers[i];
	}
}
void Graph::add_pedge(Graph* point, int length)
{
	pointers.push_back(point);
	this->length.push_back(length);
}
int Graph::get_edge_size()
{
	return pointers.size();
}
Graph* Graph::find_edge(string value)
{
	if (this->value == value)
		return this;
	else
	{
		for (int i = 0; i < pointers.size(); i++)
		{
			Graph* found = pointers[i]->find_edge(value);
			if (found != nullptr)
				return found;
		}
	}
	return nullptr;
}
bool Graph::add_edge(string value,string ins_value, int length)
{
	Graph* edge = new Graph(value);
	edge->add_pedge(edge,length);	
	if (ins_value == "-" || ins_value == value)
	{
		pointers.push_back(edge);
		this->length.push_back(length);
	}
	else
	{
		Graph* already = find_edge(value);
		if (already != nullptr)
		{
			if (already->have_edge(ins_value))
				return false;
			else 
			{
				already->add_edge(ins_value, "-", length);
			}
		}
		Graph* found = find_edge(ins_value);
		if (found != nullptr)
			found->add_edge(value, "-", length);
		else return false;
	}
	return true;
}
string Graph::get_value()
{
	return value;
}
void Graph::rec_print(vector <string>& visited,  int len, int space)
{
	bool flag = false;
	for (int i = 0; i < visited.size(); i++)
	{
		if (this->value == visited[i])
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		for (int i = 0; i < space; i++)
			cout << "  ";
		cout << "-" << len << "- " << this->value << endl;

		for (int i = 0; i < pointers.size(); i++)
		{
			pointers[i]->rec_print(visited, length[i], space + 1);

		}
	}
}
void Graph::print()
{
	cout << this->value << endl;
	vector <string> visited;
	visited.push_back(this->value);
	for (int i = 0; i < pointers.size(); i++)
	{
		pointers[i]->rec_print(visited,1,1);
	}
}
bool Graph::have_edge(string value)
{
	for (int i = 0; i < pointers.size(); i++)
	{
		if (pointers[i]->get_value() == value)
			return true;
	}
	return false;
}