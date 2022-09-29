#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;
void create_bit(string name)
{
    ofstream fb;
    fb.open(name + ".dat", ios::out | ios::binary);
    ifstream in("test.txt");
    if (not in.good())
    {
        cout << "Can't open\n";
        return;
    }
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
                    fb << (char*)&num, sizeof(int);
                }
                catch (invalid_argument const& ex)
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
            catch (invalid_argument const& ex)
            {

            }
        }
    }
    fb.close();
}
int main()
{
	
    string name;
    getline(cin, name);
    create_bit(name);
}