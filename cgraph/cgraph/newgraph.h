#ifndef __NEWGRAPH_H__
#define __NEWGRAPH_H__
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

struct Edge {
    int target;
    int length;
    int src;
    Edge(int src, int target, int length)
    {
        this->src = src;
        this->target = target;
        this->length = length;
    }
}; 

class New_graph {
private:
    //vector<list<Edge>*> edges;
    vector<vector<int>> edges;
    bool have_odd();
    bool is_connected();
    void span_recprint(int node, int spaces = 0);
public:
    void DFC(vector<bool>& visited, New_graph* &new_tree, int v = 0);
    void print();
    void add_edge(int src, int target, int length=1);
    bool euler_cycle();
    int get_size();
    void spanning_print();
};
#endif
