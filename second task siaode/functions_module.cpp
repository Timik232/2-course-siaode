#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;

string generate_random()
{
    srand(time(0));
    string asckirand;
    int amount;
    int lines = rand() % 10 + 1;
    for (int i = 0; i < lines; i++)
    {
        amount = rand() % 20 + 1;
        for (int j = 0; j < amount; j++)
        {
            int b = rand() % 10000 - 200;
            string c = to_string(b);
            asckirand += c;
            if (j != amount - 1)
                asckirand += " ";
        }
        if (i!=lines-1)
            asckirand += "\n";
    }
    return asckirand;
}

void create_file(string name)
{
    string aski = generate_random();
    ofstream f;
    f.open(name);
    if (!f.is_open())
    {
        cout << "Can't open file\n";
        return;
    }
    f << aski;
    f.close();
}

void print_file(string name)
{
    ifstream in(name);
    if (in.is_open())
    {
        cout << "File " << name << ":\n";
        while (in.good())
        {
            string line;
            getline(in, line);
            cout << line << endl;
        }
    }
    else
    {
        cout << "Can't open file\n";
        return;
    }
    in.close();
    cout << "End of file\n";
}

void add_line(string name, string line)
{
    ofstream f(name, ios::app);
    if (!f.is_open())
    {
        cout << "Can't open file\n";
        return;
    }
    f << line;
    f.close();
}

int findNumber(string name, int n)
{
    string line;
    ifstream in(name);
    int amount = 0;
    if (in.is_open())
    {
        while (in.good())
        {
            string line;
            getline(in, line);
            string buf = "";
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] != ' ')
                {
                    buf += line[i];
                }
                else
                {
                    try
                    {
                        int num = stoi(buf);
                        amount++;
                        if (amount != n)
                            buf = "";
                        else
                            return stoi(buf);
                    }
                    catch (std::invalid_argument const& ex)
                    {

                    }

                }
            }
        }
    }
    else
    {
        cout << "Can't open file\n";
        return 0;
    }
    return 0;
}

int numbersAmount(string name)
{
    string line;
    ifstream in(name);
    int amount = 0;
    if (in.is_open())
    {
        while (in.good())
        {
            string line;
            getline(in, line);
            string buf = "";
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] != ' ')
                {
                    buf += line[i];
                }
                else
                {
                    try
                    {
                        int num = stoi(buf);
                        amount++;
                    }
                    catch (std::invalid_argument const& ex)
                    {

                    }
                    buf = "";
                }
            }
            if (buf != "")
            {
                try
                {
                    int num = stoi(buf);
                    amount++;
                }
                catch (std::invalid_argument const& ex)
                {

                }
            }
        }
    }
    else
    {
        cout << "Can't open file\n";
        return 0;
    }
    return amount;
}
