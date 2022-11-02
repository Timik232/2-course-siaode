#include "menus.cpp"

int main()
{    
    char c;
    while (true)
    {
        cout << "Choose menu to interact with:\n1.Binar file\n2.Binar search tree\n3.AVL tree\n4.Exit\n";
        cin >> c;
        switch (c)
        {
        case '1':
            binar_menu();
            break;        
        case '2':
            bsearch_menu();
            break;
        case '3':
            AVL_menu();
            break;
        case '4':
            exit(0);
            break;
        default:
            cout << "Invalid input, try again\n";
            break;
        }
    }
}

