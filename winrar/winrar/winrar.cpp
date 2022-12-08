
#include "menus.cpp"

int main()
{
    setlocale(LC_ALL, "Russian");
    while (true)
    {
        cout << "Choose task (1-4)\n1.RLE\n2.Lempel-Ziv\n3.Hoffman\n4.Shannon-fano\n5.Exit\n";
        string c;
        cin >> c;
        if (c == "1")
        {
            RLE_menu();
        }
        else if (c == "2")
        {
            lempel_menu();
        }
        else if (c == "3")
        {
            hoffman();
        }
        else if (c == "4")
        {
            shenano();
        }
        else if (c == "5")
        {
            exit(0);
        }
        else
        {
            cout << "Invalid input\n";
        }
    }
}
