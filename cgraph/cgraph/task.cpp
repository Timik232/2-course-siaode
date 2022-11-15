#include "graph.cpp"
#include <string>
void personal_task()
{

}
void menu()
{
	cout << "Enter the value of the first element\n";
	string val;
	cin >> val;
	Graph* graph = new Graph(val);
	cout << "Created.\n";
	char v;
	while (true)
	{
		cout << "Choose action\n1.Add edge\n2.Print graph\n3.Have euler cycle?\n4.\n5.Exit\n";
		cin >> v;
		if (v == '1')
		{
			cout << "Enter char value of edge. To choose the edge, to which you will add edge, enter the value of edge, and to enter length, add third int value. Divided by space. Example:\n1 4 2 - which mean add element 1 to edge 4 with length 2\n";
			cout << "(If you want to choose length for this element, you should in second value write first value or '-')\n";
			string line = "";
			while (line == "")
				getline(cin, line);
			string buf = "";
			string value;
			string to_ins_val = "-";
			int len = 1;
			int count = 0;
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ' ')
				{
					if (count == 0)
					{
						value = buf;
						count += 1;
					}
					else if (count == 1)
					{
						to_ins_val = buf;
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
				value = buf;
			else if (buf != "" && count == 1)
				to_ins_val = buf;
			else if (buf != "" && count == 2)
				len = stoi(buf);
			if (graph->add_edge(value, to_ins_val, len))
				cout << "Edge was added\n";
			else cout << "Can't find element to add edge or already exist\n";
		}
		else if (v == '2')
		{
			graph->print();
		}
		else if (v == '3')
		{

		}
		else if (v == '4')
		{

		}
		else if (v == '5')
			return;
	}
}