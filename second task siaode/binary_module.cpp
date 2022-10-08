#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;
struct student
{
    string fullName;
    int groupNumber;
    int studentNumber;
    int key;
};
void create_bit(string name)
{
    ofstream fb;
    fb.open(name + ".dat", ios::out | ios::binary);
    ifstream in("test.txt");
    if (!fb.is_open())
    {
        cout << "Can't create file\n";
        return;
    }
    while (in.good())
    {
        string line;
        getline(in, line);
        string buf = "";
        student st;
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != ' ')
            {
                buf += line[i];
            }
            else
            {                   
                fb.write((char*)&st, sizeof(student));
                buf = "";
            }
        }
        if (buf != "")
        {           
            fb.write((char*)&buf, sizeof(student));          
        }
    }
    fb.close();
    in.close();
}
void print_file(string name)
{
    ifstream fb(name + ".dat", ios::in | ios::binary);
    if (!fb.good())
    {
        cout << "Can't open file!\n";
        return;
    }
    while (fb.good())
    {
        int x;
        fb.read((char*)&x, sizeof(student));
        cout << x << " ";

    }
    cout << endl;
    fb.close();
}
void text_to_binar(string textName,string name)
{
    ofstream fb(name + ".dat", ios::out | ios::binary);
    ifstream in(textName + ".txt", ios::in);
    if (!fb.good())
    {
        cout << "Can't open binary file!\n";
        return;
    }
    if (!in.good())
    {
        cout << "Can't open text file!\n";
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
                    fb.write((char*)&buf, sizeof(student));
                }
                buf = "";
            }
        }
        if (buf != "")
        {
            try
            {
                int num = stoi(buf);
                fb.write((char*)&num, sizeof(student));
            }
            catch (invalid_argument const& ex)
            {

            }
        }
    }
    fb.close();
    in.close();
}
void binar_to_text(string textName, string name)
{
    ifstream fb(name + ".dat", ios::in | ios::binary);
    ofstream txt(textName + ".txt", ios::out);
    if (!fb.good())
    {
        cout << "Can't open binary file!\n";
        return;
    }
    if (!txt.good())
    {
        cout << "Can't open text file!\n";
        return;
    }
    while (fb.good())
    {
        int x;
        fb.read((char*)&x, sizeof(int));
        

    }
}