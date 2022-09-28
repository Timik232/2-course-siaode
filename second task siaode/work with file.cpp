#include "functions_module.cpp"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Enter name of file (with extension)\n";
    string name;
    getline(cin, name);
    create_file(name);
    cout << "Choose action with file(1-7):\n1.Add line from keyboard\n2.Print file\n3.Print amount of numbers in file\n4.Find number by index\n5.Common tests of all functions\n6.Personal task-test (12)\n7.Exit\n";
    while(true)
    {
        char choose;
        cin >> choose;
        if (choose == '1')
        {
            
            string line = "";
            string buf = "";
            cout << "Write a line to add into the file\n";
            while (line == "")
            {
                getline(cin, line);
                buf += line;
            }
            
            add_line(name, buf);
            cout << "Line was added\n";
            cin.clear();
        }
        else if (choose == '2')
        {
            print_file(name);
        }
        else if (choose == '3')
        {
            cout << "There is " << numbersAmount(name) << " numbers in the file\n";
        }
        else if (choose == '4')
        {
            cout << "Enter number's index\n";
            int n;
            cin >> n;
            cout << "Number with index " << n << " is " << findNumber(name, n) << endl;
        }
        else if (choose == '5')
        {

            print_file(name);
            add_line(name, "1 2 3 4 5");
            print_file(name);
            cout << "Number with index 3 is " << findNumber(name, 3) << endl;
            cout << "There is " << numbersAmount(name) << " numbers in the file\n";
        }
        else if (choose == '6')
        {
            new_file(name);
        }
        else if (choose == '7')
        {
            exit(0);
        }
        else cout << "Invalid input, try again\n";
    }
}