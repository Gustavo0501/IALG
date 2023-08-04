#include <iostream>

using namespace std;

int main()
{
    float kg, altura;

    cin >> kg >> altura;

    if (altura < 1.2)
    {
        if (kg < 60)
        {
            cout << 'A' << endl;
        }
        if (kg >= 60 && kg <= 90)
        {
            cout << 'D' << endl;
        }
        if (kg > 90)
        {
            cout << 'G' << endl;
        }
    }

    if (altura >= 1.20 && altura <= 1.7)
    {
        if (kg < 60)
        {
            cout << 'B' << endl;
        }
        if (kg >= 60 && kg <= 90)
        {
            cout << 'E' << endl;
        }
        if (kg > 90)
        {
            cout << 'H' << endl;
        }
    }

    if (altura > 1.7)
    {
        if (kg < 60)
        {
            cout << 'C' << endl;
        }
        if (kg >= 60 && kg <= 90)
        {
            cout << 'F' << endl;
        }
        if (kg > 90)
        {
            cout << 'I' << endl;
        }
    }

    return 0;
}