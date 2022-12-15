
#include <iostream>

using namespace std;
#include "newgraph.cpp"

int main()
{
	New_graph* gr = new New_graph();
    gr->add_edge(0, 1);
    gr->add_edge(0, 3);
    gr->add_edge(0, 4);
    gr->add_edge(0, 2);
    gr->add_edge(3, 1);
    gr->add_edge(3, 4);
    gr->add_edge(1, 2);
    gr->add_edge(1, 4);
    gr->add_edge(2, 4);
    gr->print();
    if (gr->have_hamiltonian())
        cout << "Graph have hamiltonian cycle\n";
    else
    {
        cout << "Graph haven't hamiltonian cycle\n";
        exit(0);
    }
    vector<vector <int>> hamilts = gr->all_hamiltonian();
    cout << "All hamiltonian graphs:\n";
    
    for (int i = 0; i < hamilts.size(); i++)
    {
        cout << 0 << "->" << hamilts[i][0];
        for (int j = 0; j < hamilts[i].size(); j++)
            cout << "->" << hamilts[i][j];
    }
    cout << endl;
}

