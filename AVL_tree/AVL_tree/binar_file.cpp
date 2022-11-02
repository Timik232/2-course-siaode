#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <iomanip>
#include "business.h"
#include "binar_file.h"
using namespace std;

void binar_file::create_bit(string name)
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
        business st;
        in >> st.license;
        in >> st.name;
        in >> st.founder;
        string buf;
        getline(in, buf);
        if (buf == "1")
            st.isActive = true;
        else st.isActive = false;
        in.get();
        fb.write((char*)&st, sizeof(business));
    }
    fb.close();
    in.close();
}
void binar_file::print_file(string name)
{
    ifstream fb(name + ".dat", ios::binary);
    if (!fb.good())
    {
        cout << "Can't open file!\n";
        return;
    }
    business st;
    fb.read((char*)&st, sizeof(business));
    cout << "Name" << setw(23) << "founder" << setw(15) << "license" << setw(10) << "status\n";
    while (fb.good())
    {
        cout << left << setw(20) << st.name << setw(15) << st.founder << setw(10) << st.license;
        if (st.isActive)
            cout << setw(10) << "active" << endl;
        else cout << setw(10) << "not active" << endl;
        fb.read((char*)&st, sizeof(business));
    }
    cout << endl;
    fb.close();
}
bool binar_file::text_to_binar(string textName, string name)
{
    ofstream fb;
    fb.open(name + ".dat", ios::out | ios::binary);
    ifstream in(textName + ".txt", ios::in);
    if (!fb.good())
    {
        cout << "Can't open binary file!\n";
        return false;
    }
    if (!in.good())
    {
        cout << "Can't open text file!\n";
        return false;
    }
    while (in.good())
    {
        business st;
        in >> st.license;
        in >> st.name;
        in >> st.founder;
        char buf;
        in >> buf;
        if (buf == '1')
            st.isActive = true;
        else st.isActive = false;
        in.get();
        fb.write((char*)&st, sizeof(business));
    }
    fb.close();
    in.close();
    return true;
}
bool binar_file::binar_to_text(string textName, string name)
{
    ifstream fb;
    fb.open(name + ".dat", ios::binary);
    ofstream txt(textName + ".txt", ios::out);
    if (!fb.good())
    {
        cout << "Can't open binary file!\n";
        return false;
    }
    if (!txt.good())
    {
        cout << "Can't open text file!\n";
        return false;
    }
    business st;
    fb.read((char*)&st, sizeof(business));
    txt << st.license << "\n" << st.name << "\n" << st.founder << "\n";
    if (st.isActive)
        txt << "1";
    else txt << "0";
    fb.read((char*)&st, sizeof(business));
    while (fb.good())
    {
        txt << st.license << "\n" << st.name << "\n" << st.founder << "\n";
        if (st.isActive)
            txt << "1";
        else txt << "0";
        fb.read((char*)&st, sizeof(business));
    }
    return true;
}
business binar_file::get_by_index(string name, int index)
{
    ifstream fb;
    business result;
    fb.open(name + ".dat", ios::binary);
    if (!fb.good())
    {
        cout << "Can't open binary file!\n";
        result.name[0] = '0';
        return result;
    }
    fb.seekg(index * sizeof(business));
    fb.read((char*)&result, sizeof(business));
    fb.close();
    return result;
}
bool binar_file::delete_by_key(string name, string key)
{
    fstream fb;
    fb.open(name + ".dat", ios::out | ios::in | ios::binary);
    if (!fb.good())
    {
        cout << "Can't open binary file!\n";
        return false;
    }
    business lastElement;
    business bufElement;
    fb.read((char*)&lastElement, sizeof(business));
    while (fb.good())
        fb.read((char*)&lastElement, sizeof(business));
    fb.close();
    fb.open(name + ".dat", ios::out | ios::in | ios::binary);
    fb.read((char*)&bufElement, sizeof(business));
    while (fb.good() && bufElement.license != key)
    {
        fb.read((char*)&bufElement, sizeof(business));
    }
    fb.seekp(sizeof(bufElement) * (-1), ios::cur);
    fb.write((char*)&lastElement, sizeof(business));
    return true;
}
bool binar_file::insert_element(string name, business st)
{
    ofstream fb(name + ".dat", ios::app | ios::binary);
    if (!fb.good())
    {
        cout << "Can't open binary file!\n";
        return false;
    }
    fb.write((char*)&st, sizeof(business));
    fb.close();
    return true;
}
//personal
bool founder_list(string name, string founder)
{
    ifstream fb;
    fb.open(name + ".dat", ios::in | ios::binary);
    if (!fb.good())
    {
        cout << "Can't open binary file!\n";
        return false;
    }
    string some_licenses = "";
    business to_find;
    fb.read((char*)&to_find, sizeof(business));
    while (fb.good())
    {
        if (to_find.founder == founder)
        {
            some_licenses += to_find.license;
            some_licenses += " ";
        }
        fb.read((char*)&to_find, sizeof(business));
    }
    if (some_licenses == "")
    {
        cout << "This founder hasn't licenses\n";
        return false;
    }
    ofstream txt;
    txt.open(founder + ".txt", ios::out);
    txt << "List of licenses of founder " << founder << "\n";
    string buf;
    int count = 0;
    while (some_licenses != "")
    {
        if (some_licenses[count] == ' ')
        {
            some_licenses.replace(0, count + 1, "");
            txt << buf << "\n";
            buf = "";
            count = 0;
        }
        buf += some_licenses[count];
        count += 1;
    }
    return true;
}

bool revoke_licenses(string name, string textName)
{
    ifstream txt(textName + ".txt", ios::in);
    fstream fb(name + ".dat", ios::in | ios::binary);
    if (!fb.good())
    {
        cout << "Can't open binary file!\n";
        return false;
    }
    fb.close();
    if (!txt.good())
    {
        cout << "Can't open text file!\n";
        return false;
    }
    while (txt.good())
    {
        string license;
        getline(txt, license);
        business bufElement;
        fstream fb(name + ".dat", ios::in | ios::out | ios::binary);
        while (fb.good())
        {
            fb.read((char*)&bufElement, sizeof(business));
            if (bufElement.license == license)
            {
                bufElement.isActive = false;
                fb.seekp(sizeof(bufElement) * (-1), ios::cur);
                fb.write((char*)&bufElement, sizeof(business));
                fb.close();
            }
        }
    }
    return true;
}