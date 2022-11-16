#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <iostream>
#include <vector>
using namespace std;
class Graph {
private:
	vector <Graph*> pointers;
	vector <int> length;
	string value;
	void add_pedge(Graph* point,int length=1);
	void rec_print(int len,int space = 0);
	
public:
	Graph(string value);
	~Graph();
	bool add_edge(string value, string ins_value = "-", int length = 1);
	Graph* find_edge(string value);
	void print();
	bool have_edge(string val);
	string get_value();
	int get_edge_size();
	bool euler_cycle(bool is_first = false);
};
#endif