
#include "tree_module.cpp"

int main()
{    
    cout << "Choose: \n1)Ready test \n2)Input and create tree\n3)Print tree\n4)Infix from\n5)Postifx form\n6)Exit\n";
    char ch;
    btree* tree = nullptr;
    while (true)
    {
        cin >> ch;
        if (ch == '1')
        {
            //string test = "12+456*+*";
            //string test = "ab+cde+**";
            string test = "ab+cde+**";
            cout << "Postfix string for test: " << test << endl;
            btree* test_tree;
            test_tree = create_tree(test);
            cout << "Binary tree:\n";
            print_tree(test_tree);            
            //postorder(test_tree);
            //cout << endl;
            //inorder(test_tree);
        }
        else if (ch == '2')
        {
            cout << "Input postfix line\n";
            string line = "";
            while(line=="")
                getline(cin, line);
            tree = create_tree(line);
            cout << "Tree was created\n";
        }
        else if (ch == '3')
        {
            print_tree(tree);
        }
        else if (ch == '4')
        {
            cout << "Infix is: ";
            inorder(tree);
            cout << endl;
        }
        else if (ch == '5')
        {
            cout << "Postfix is: ";
            postorder(tree);
            cout << endl;
        }
        else if (ch == '6')
            exit(0);
        else cout << "Invalid input, try again\n";
    }
}
