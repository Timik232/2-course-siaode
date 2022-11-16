#include "graph.cpp"
#include "newgraph.cpp"
#include <string>

void spanning_tree() //остовное дерево
{
	cout << "Not completed yet\n";
}

void menu(New_graph* graph = nullptr)
{
	if (graph == nullptr)
	{
		//cout << "Enter the value of the first element\n";
		string val;
		//cin >> val;
		//graph = new Graph(val);
		graph = new New_graph();
		cout << "Created.\n";
	}
	char v;
	cout << "Choose action\n1.Add edge\n2.Print graph\n3.Have euler cycle?\n4.Spanning tree\n5.Exit\n";
	while (true)
	{		
		cin >> v;
		if (v == '1')
		{
			cout << "Enter 2 elements, between them will be built edge. Third parameter is optional: length of edge\n";
			//cout << "Enter char value of edge. To choose the edge, to which you will add edge, enter the value of edge, and to enter length, add third int value. Divided by space. Example:\n1 4 2 - which mean add element 1 to edge 4 with length 2\n";
			//cout << "(If you want to choose length for this element, you should in second value write first value or '-')\n";
			string line = "";
			while (line == "")
				getline(cin, line);
			string buf = "";
			int value;
			int to_ins_val;
			int len = 1;
			int count = 0;
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ' ')
				{
					if (count == 0)
					{
						value = stoi(buf);
						count += 1;
					}
					else if (count == 1)
					{
						to_ins_val = stoi(buf);
						count += 1;
					}
					else if (count == 2)
					{
						len = stoi(buf);
						count += 1;
					}
					buf = "";
				}
				else
					buf += line[i];
			}
			if (buf != "" && count == 0)
				value = stoi(buf);
			else if (buf != "" && count == 1)
				to_ins_val = stoi(buf);
			else if (buf != "" && count == 2)
				len = stoi(buf);
			graph->add_edge(value, to_ins_val, len);
			cout << "Edge was added\n";
			//else cout << "Can't find element to add edge or already exist\n";
		}
		else if (v == '2')
		{
			graph->print();
		}
		else if (v == '3')
		{
			if (graph->euler_cycle())
				cout << "Graph is euler\n";
			else cout << "Graph isn't euler\n";
		}
		else if (v == '4')
		{
			spanning_tree();
		}
		else if (v == '5')
			return;
		else cout << "Invalid input, try again\n";
	}
}