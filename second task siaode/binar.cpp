#include "binary_module.cpp"
int main()
{
    /*cout << "Enter name of file\n";
    string name;
    getline(cin, name);
    create_bit(name);*/
    cout << "Choose action with file(1-7):\n1.From text file to binary (create binary file)\n2.Print file\n3.From binary file to text\n4.Find element by index\n5.Delete by key (license)\n6.Personal task-test (12)\n7.Exit\n";
    while (true)
    {
        char choose;
        cin >> choose;
        if (choose == '1')
        {
            string line = "";
            string buf = "";
            cout << "Write a name of file from which we will take data\n";
            while (line == "")
            {
                getline(cin, line);
                buf += line;
            }
            cout << "Enter name of binary file\n";
            string name;
            while (name == "")
                getline(cin, name);
            if (text_to_binar(buf, name))
                cout << "Data from text file was added\n";
            cin.clear();
        }
        else if (choose == '2')
        {
            cout << "Enter the name of binary file\n";
            string name = "";
            while (name == "")
                getline(cin, name);
            print_file(name);
        }
        else if (choose == '3')
        {
            string line = "";
            string buf = "";
            cout << "Write a name of text file to which we will write binary\n";
            while (line == "")
            {
                getline(cin, line);
                buf += line;
            }
            cout << "Enter name of binary file\n";
            string name = "";
            while (name == "")
                getline(cin, name);
            if (binar_to_text(buf, name))
                cout << "Data from binary file was added to text\n";
            cin.clear();
        }
        else if (choose == '4')
        {
            cout << "Enter name of binary file\n";
            string name = "";
            while (name == "")
                getline(cin, name);
            cout << "Enter number's index\n";
            int n;
            cin >> n;            
            cout << "Name of business with index " << n << " is " << get_by_index(name, n).name << endl;
        }
        else if (choose == '5')
        {
            cout << "Enter name of binary file\n";
            string name = "";
            while (name == "")
                getline(cin, name);
            cout << "Print license of business, which you want to delete\n";
            string key = "";
            getline(cin, key);
            if (delete_by_key(name, key))
                cout << "Was replaced by the last element\n";
        }
        else if (choose == '6')
        {
            cout << "Enter name of binary file\n";
            string name = "";
            while (name == "")
                getline(cin, name);
            cout << "Enter name of founder\n";
            string founder;
            getline(cin, founder);
            founder_list(name, founder);
        }
        else if (choose == '7')
        {
            exit(0);
        }
        else cout << "Invalid input, try again\n";
    }
}