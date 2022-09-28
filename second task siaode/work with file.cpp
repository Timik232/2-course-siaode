#include "functions_module.cpp"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Enter name of file (with extension)\n";
    string name;
    getline(cin, name);
    create_file(name);
    cout << "Choose action with file(1-6):\n1.Add line from keyboard\n2.Print file\n3.Print amount of numbers in file\n4.Find number by index\n5.Common tests of all functions\n6.Exit\n";
    while(true)
    {
        char choose;
        cin >> choose;
        string line;
        switch (choose)
        {
        case '1':
            cout << "Write a line to add into the file\n";
            getline(cin, line);
            add_line(name, line);
            cout << "Line was added\n";
            break;
        case '2':
            print_file(name);
            break;
        case '3':
            cout << "There is " << numbersAmount(name) << " numbers in the file\n";
            break;
        case '4':
            cout << "Enter number's index\n";
            int n;
            cin >> n;
            cout << "Number with index " << n << " is " << findNumber(name, n) << endl;
            break;
        case '5':
            print_file(name);
            add_line(name, "1 2 3 4 5");
            print_file(name);
            cout << "Number with index 3 is " << findNumber(name, 3) << endl;
            cout << "There is " << numbersAmount(name) << " numbers in the file\n";
            break;
        case '6':
            exit(0);
            break;
        }
    }
}