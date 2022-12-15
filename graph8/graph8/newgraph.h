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
    
public:
    bool have_edge(int val1, int val2, vector <bool>&visited);
    void DFC(vector<bool>& visited, New_graph* &new_tree, int v = 0);
    void print();
    void add_edge(int src, int target, int length=1);
    int get_size();
    bool have_hamiltonian();
    vector <vector <int>> all_hamiltonian();
};
#endif
