#include "Bsearch_tree.cpp"
#include "binar_file.cpp"
#include "AVL_tree.cpp"
void binar_menu()
{
    binar_file bfile = binar_file();
    cout << "Choose action with file(1-7):\n1.From text file to binary (create binary file)\n2.Print file\n3.From binary file to text\n4.Find element by index\n5.Delete by key (license)\n6.Personal task part one (12 - make founder's file)\n7.Personal task part two(12 - revoke license)\n8.Insert element\n9.Exit\n";
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
            if (bfile.text_to_binar(buf, name))
                cout << "Data from text file was added\n";
            cin.clear();
        }
        else if (choose == '2')
        {
            cout << "Enter the name of binary file\n";
            string name = "";
            while (name == "")
                getline(cin, name);
            bfile.print_file(name);
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
            if (bfile.binar_to_text(buf, name))
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
            cout << "Name of business with index " << n << " is " << bfile.get_by_index(name, n).name << endl;
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
            if (bfile.delete_by_key(name, key))
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
            if (founder_list(name, founder))
                cout << "File was generated\n";
        }
        else if (choose == '7')
        {
            cout << "Enter name of binary file\n";
            string name = "";
            while (name == "")
                getline(cin, name);
            cout << "Enter name of text file with license\n";
            string textName;
            getline(cin, textName);
            if (revoke_licenses(name, textName))
                cout << "Licenses were revoked\n";
        }
        else if (choose == '8')
        {
            cout << "Enter name of binary file\n";
            string name;
            while (name == "")
                getline(cin, name);
            cout << "Enter all information about business in format:\n license \nname \nfounder \nactive (0 or 1)\n";
            business st;
            cin >> st.license;
            cin >> st.name;
            cin >> st.founder;
            char buf;
            cin >> buf;
            if (buf == 1)
                st.isActive = true;
            else
                st.isActive = false;
            if (bfile.insert_element(name, st))
                cout << "Element was added\n";
        }
        else if (choose == '9')
        {
            return;
        }
        else cout << "Invalid input, try again\n";
    }
}
void bsearch_menu()
{
    Bsearch_tree tree;
    cout << "Choose action with Binar Search Tree:\n1.Build tree from file\n2.Print tree\n3.Find element in the tree by key\n4.Insert element\n5.Delete element by key\n6.Exit\n";
    char c;
    while (true)
    {
        cin >> c;
        if (c == '1')
        {
            tree = Bsearch_tree();
            cout << "Enter name of binar file (without extension)\n";
            string name;
            cin >> name;
            if (tree.build_tree(name))
            {
                cout << "Tree was builded\n";
            }
            else cout << "Invalid name of file, choose task again\n";
        }
        /*else if (c == '2')
        {
            cout << "Entry license and number in format:\nlicense 3\n";
            string license;
            int numb;
            cin >> license;
            cin >> numb;
            tree = Bsearch_tree(license, numb);
            cout << "Tree with first element was created\n";
        }*/
        else if (c == '2')
        {
            tree.print_tree();
        }
        else if (c == '3')
        {
            cout << "Enter key-license to find element\n";
            string license = "";
            cin >> license;
            Tree_element* found = tree.find(license);
            if (found)
                cout << "Element was found, license and number are:\n" << found->license << " " << found->number << endl;
            else
                cout << "Wasn't found\n";
        }
        else if (c == '4')
        {
            cout << "Entry license and number in format:\nlicense 3\n";
            string license;
            int numb;
            cin >> license;
            cin >> numb;
            tree.insert(license,numb);
            cout << "Element was inserted\n";
        }
        else if (c == '5')
        {
            cout << "Entry license to delete\n";
            string license = "";
            cin >> license;
            if (tree.erase(license))
                cout << "Element was deleted\n";
            else cout << "Element wasn't found\n";
        }
        else if (c == '6')
        {
            return;
        }
        else
        {
            cout << "Invalid input, try again\n";
        }
    }
        
}
void AVL_menu()
{
    AVL_tree tree;
    cout << "Choose action with Binar Search Tree:\n1.Build tree from file\n2.Print tree\n3.Insert element\n4.Delete element by key\n5.Exit\n";
    char c;
    while (true)
    {
        cin >> c;
        if (c == '1')
        {
            tree = AVL_tree();
            cout << "Enter name of binar file (without extension)\n";
            string name;
            cin >> name;
            if (tree.build_tree(name))
            {
                cout << "Tree was builded\n";
            }
            else cout << "Invalid name of file, choose task again\n";
        }
        /*else if (c == '2')
        {
            cout << "Entry license and number in format:\nlicense 3\n";
            string license;
            int numb;
            cin >> license;
            cin >> numb;
            tree = AVL_tree(license, numb);
            cout << "Tree with first element was created\n";
        }*/
        else if (c == '2')
        {
            tree.print_tree();
        }
        else if (c == '3')
        {
            cout << "Entry license and number in format:\nlicense 3\n";
            string license;
            int numb;
            cin >> license;
            cin >> numb;
            tree.insert(license, numb);
            cout << "Element was inserted\n";
        }
        else if (c == '4')
        {
            cout << "Entry license to delete\n";
            string license = "";
            cin >> license;
            if (tree.erase(license))
                cout << "Element was deleted\n";
            else cout << "Element wasn't found\n";
        }
        else if (c == '5')
        {
            return;
        }
        else
        {
            cout << "Invalid input, try again\n";
        }
    }
}
