//Отдельно задание стекстовым файломповарианту, потом сделать двоичный файл, затем их преобразовать один в другой, затем вывести из двоичного в консоль

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;

string generate_random()
{
    srand(time(0));
    string asckirand;
    for (int i = 0; i < 1000; i++)
    {
        int b = rand() % 10000 - 200;
        string c = to_string(b);
        asckirand+=c;
    }
    return asckirand;
}
void create_file()
{
    string aski = generate_random();
    cout << "Enter name of file (with extension)\n";
    string name;
    getline(cin, name);
    ofstream f;
    f.open(name);//создаём файл
    if (!f.is_open())	//проверка существования файла с именем A.txt
    {
        cout << "Can't open file\n";
        return;
    }
    f << aski;
    f.close();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    create_file();
    cout << "warum";
    //ifstream input("rand.txt");
    //cout << aski;
}
