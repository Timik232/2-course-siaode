#include "task.cpp"


int main()
{
    cout << "Note: this code is for undirected graphs, as at task\n";
    string c;
    while (true)
    {
        cout << "Choose action\n1.Create your own graph\n2.Test graph\n3.Exit\n";
        cin >> c;
        if (c == "1")
        {
            menu();
        }
        else if (c == "2") //выбрал 9; в задании нужно создать неориентированный граф, поэтому у меня все графы неориентированные
        {
            New_graph* gr = new New_graph();
            /*gr->add_edge('B', 'B', 7);
            gr->add_edge('N', 'N', 10);
            gr->add_edge('G', "B", 9);
            gr->add_edge("G", "N", 8);
            gr->add_edge("R", "N", 31);
            gr->add_edge("S", "G", 11);
            gr->add_edge("D", "R", 32);
            gr->add_edge("S", "D", 17);
            gr->add_edge("M", "S", 15);
            gr->add_edge("M", "D", 21);
            gr->add_edge("A", "B", 27);
            gr->add_edge("A", "M", 9);*/
            
            gr->add_edge(0, 1, 7);
            gr->add_edge(0, 2, 10);
            gr->add_edge(3, 1, 9);
            gr->add_edge(3, 2, 8);
            gr->add_edge(4, 2, 31);
            gr->add_edge(5, 3, 11);
            gr->add_edge(6, 4, 32);
            gr->add_edge(5, 6, 17);
            gr->add_edge(8, 5, 15);
            gr->add_edge(8, 6, 21);
            gr->add_edge(7, 1, 27);
            gr->add_edge(7, 8, 9);
            gr->print();
            menu(gr);
        }
        else if (c == "3")
        {
            exit(0);
        }
        else
            cout << "Invalid input, try again\n";
    }
}

