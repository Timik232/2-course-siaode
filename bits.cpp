//7 9 11
//только с чётными номерами
//128
//128
//обнулить бит в 0 используя маску 1 вариант
#include <iostream>
using namespace std;

string to_bit(unsigned short bit)
{
    string output = "";
    unsigned short mask = 0b1000000000000000;
    for (int i = 0; i < 16; i++)
    {
        
        if (mask & bit)
            output += "1";
        else output += "0";
        mask >>= 1;

    }
    return output;
}

void cout_result(unsigned short bit)
{
    cout << "Result is: \ndec     hex     bits\n";
    cout << dec << bit << "     " << hex << bit << "     ";
    string output = to_bit(bit);
    cout << output << endl;
}

unsigned short task1(unsigned short s, unsigned short mask)
{
    return s | mask;
}
unsigned short task2(unsigned short s, unsigned short mask)
{
    return s & mask;
}
unsigned short task3(unsigned short s, unsigned short mask)
{
    return s <<= mask;
}
unsigned short task4(unsigned short s, unsigned short mask)
{
    return s >>= mask;
}
unsigned short task5(unsigned short &s, unsigned short &mask, unsigned short n)
{
    mask <<= n;
    //s = s | mask; //чтобы в 1
    mask = ~mask;
    s = s & mask; //чтобы в 0
    return s;
}

int main()
{
    while (true)
    {
        cout << "Choose task (1-6) (or exit):\n1.set 1 at 7, 9 and 11 bits\n2.set 0 at even numbers\n3.Multiply numbers\n4.Divide numbers\n5.Set to 0 bits\n6.Exit\n";
        char t;
        cin >> t;
        unsigned short s;
        unsigned short mask;
        switch (t)
        {
        case '1':
            s = 0x0000;
            cout << "Original number: " << hex << s << endl;
            mask = 0b0000101010000000;
            cout << "Mask: " << to_bit(mask) << endl;
            s = task1(s, mask);
            
            cout_result(s);
            cout << endl;
            break;
        case '2':
            cout << "Enter number\n";
            cin >> s;
            cout << "Original number: " << dec << s << endl;
            mask = 0b1010101010101010;
            s = task2(s, mask);
            cout << "Mask: " << to_bit(mask) << endl;
            cout_result(s);
            cout << endl;
            break;
        case '3':
            cout << "Enter number\n";
            cin >> s;
            cout << "Original number: " << dec << s << endl;
            mask = 7;
            s = task3(s, mask);
            cout << "Mask: " << to_bit(mask) << endl;
            cout_result(s);
            cout << endl;
            break;
        case '4':
            cout << "Enter number\n";
            cin >> s;
            cout << "Original number: " << dec << s << endl;
            mask = 7;
            s = task4(s, mask);
            cout << "Mask: " << to_bit(mask) << endl;
            cout_result(s);
            cout << endl;
            break;
        case '5':
            cout << "Enter number\n";
            cin >> s;
            
            mask = 0b0000000000000001;
            
            cout << "Enter n: this bit will be 0\n";
            unsigned short n;
            cin >> n;
            cout << "bit is " << n << endl;
            cout << "Original number: " << dec << s << endl;
            cout << "Mask in beginning: " << to_bit(mask) << endl;
            s = task5(s, mask, n);
            cout << "Mask in the end: " << to_bit(mask) << endl;
            cout_result(s);
            cout << endl;
            break;
        case '6':
            exit(0);
        default:
            cout << "Invalid input, try again\n";
        }
    }
}
