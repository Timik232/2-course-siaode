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
	//edge->add_pedge(this,length);	
	if (ins_value == "-" || ins_value == value)
	{
		pointers.push_back(edge);
		this->length.push_back(length);
	}
	else
	{
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
void Graph::rec_print(int len, int space)
{
		for (int i = 0; i < space; i++)
			cout << "  ";
		cout << "-" << len << "- " << this->value << endl;
		for (int i = 0; i < pointers.size(); i++)
		{
			pointers[i]->rec_print(length[i], space + 1);

		}
}
void Graph::print()
{
	cout << this->value << endl;
	for (int i = 0; i < pointers.size(); i++)
	{
		pointers[i]->rec_print(1,1);
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
bool Graph::euler_cycle(bool is_first)
{
	if (is_first)
	{
		if (pointers.size() % 2 != 0)
			return false;
	}
	else
	{
		if ((pointers.size() + 1) % 2 != 0) //добавляем 1, посколкьу в самих графах нет указателя на тот граф, который его создал
			return false;
	}
	for (int i = 0; pointers.size(); i++)
	{
		if (!pointers[i]->euler_cycle())
			return false;
	}
	return true;
}