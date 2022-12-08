
#include "menus.cpp"
#include <fstream>

int main()
{
    setlocale(LC_ALL, "Russian");
    while (true)
    {
        cout << "Choose task (1-4)\n1.RLE\n2.Lempel-Ziv\n3.Huffman\n4.Shannon-fano\n5.Compress large file with Huffman\n6.Exit\n";
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
            ifstream f;
            f.open("large.txt");
            string line;
            string large = "";
            while (!f.eof())
            {
                getline(f, line);
                large += line;
            }
            hoffman(large);
            f.close();
        }
        else if (c == "6")
        {
            exit(0);
        }
        else
        {
            cout << "Invalid input\n";
        }
    }
}
