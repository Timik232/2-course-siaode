
//7 9 11
//только с чётными номерами
//128
//128
//обнулить бит в 0 используя маску 1 вариант
#include <iostream>
using namespace std;

void cout_result(unsigned short bit)
{
    cout << "Result is: \ndec     hex     bits\n";
    cout << dec << bit << "     " << hex << bit << "     ";
    unsigned short mask = 0b1000000000000000;
    string output = "";
    for (int i = 0; i < 16; i++)
    {
        if (mask & bit)
            output += "1";
        else output += "0";
        mask >>= 1;

    }
    cout << output << endl;
}
void task1()
{
    unsigned short s = 0x0000;
    unsigned short mask = 0b0000101010000000;
    s = s | mask;
    cout_result(s);
}
void task2()
{
    cout << "Enter hex-number\n";
    unsigned short s;
    cin >> hex >> s;
    unsigned short mask = 0b1010101010101010;
    s = s & mask;
    cout_result(s);
}
void task3()
{
    unsigned short s;
    cout << "Enter hex-number\n";
    cin >> hex >> s;
    unsigned short mask = 7;
    s <<= mask;
    cout_result(s);
}
void task4()
{
    unsigned short s;
    cout << "Enter hex-number\n";
    cin >> hex >> s;
    unsigned short mask = 7;
    s >>= mask;
    cout_result(s);
}
void task5()
{
    unsigned short s;
    cout << "Enter hex-number\n";
    cin >> hex >> s;
    unsigned short mask = 0b0000000000000001;
    cout << "Enter n: this bit will be 0\n";
    unsigned short n;
    cin >> n;
    mask <<= n;
    //s = s | mask; //чтобы в 1
    mask = ~mask;
    s = s & mask; //чтобы в 0
    cout_result(s);
}

int main()
{
    while (true)
    {
        cout << "Choose task (1-6) (or exit):\n1.set 1 at 7, 9 and 11 bits\n2.set 0 at even numbers\n3.Multiply numbers\n4.Divide numbers\n5.Set to 0 bits\n6.Exit\n";
        char t;
        cin >> t;
        switch (t)
        {
        case '1':
            task1();
            break;
        case '2':
            task2();
            break;
        case '3':
            task3();
            break;
        case '4':
            task4();
            break;
        case '5':
            task5();
            break;
        case '6':
            exit(0);
        default:
            cout << "Invalid input, try again\n";
        }
    }
}
