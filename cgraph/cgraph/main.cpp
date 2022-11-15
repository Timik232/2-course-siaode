#include "task.cpp"


int main()
{
    cout << "Choose action\n1.Create your own graph\n2.Test graph\n3.Exit\n";
    string c;
    while (true)
    {
        cin >> c;
        if (c == "1")
        {
            menu();
        }
        else if (c == "2") //выбрал 9; в задании нужно создать неориентированный граф, поэтому у меня все графы неориентированные
        {
            Graph* gr = new Graph("L");
            gr->add_edge("B","B",7);
            gr->add_edge("N","N",10);
            gr->add_edge("G", "B",9);
            gr->add_edge("G", "N", 8);
            gr->add_edge("R", "N", 31);
            gr->add_edge("S", "G", 11);
            gr->add_edge("D", "R", 32);
            gr->add_edge("S", "D", 17);
            gr->add_edge("M", "S", 15);
            gr->add_edge("M", "D", 21);
            gr->add_edge("A", "B", 27);
            gr->add_edge("A", "M", 9);
            gr->print();
        }
        else if (c == "3")
        {
            exit(0);
        }
    }
}

