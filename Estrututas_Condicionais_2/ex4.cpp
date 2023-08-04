#include <iostream>

using namespace std;

int main()
{
    int idade;
    float kg;

    cin >> idade >> kg;

    if (idade < 20)
    {
        if (kg < 60)
        {
            cout << 9 << endl;
        }
        if (kg >= 60 && kg <= 90)
        {
            cout << 8 << endl;
        }
        if (kg > 90)
        {
            cout << 7 << endl;
        }
    }

    if (idade >= 20 && idade <= 50)
    {
        if (kg < 60)
        {
            cout << 6 << endl;
        }
        if (kg >= 60 && kg <= 90)
        {
            cout << 5 << endl;
        }
        if (kg > 90)
        {
            cout << 4 << endl;
        }
    }

    if (idade > 50)
    {
        if (kg < 60)
        {
            cout << 3 << endl;
        }
        if (kg >= 60 && kg <= 90)
        {
            cout << 2 << endl;
        }
        if (kg > 90)
        {
            cout << 1 << endl;
        }
    }

    return 0;
}