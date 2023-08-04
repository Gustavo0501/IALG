#include <iostream>

using namespace std;

int main()
{
    double A, B;
    int X;

    cin >> A >> B >> X;

    if (X == 1)
    {
        cout << (A + B) / 2 << endl;
    }
    if (X == 2)
    {
        if (A < B)
        {
            cout << B - A << endl;
        }
        else
        {
            cout << A - B << endl;
        }
    }
    if (X == 3)
    {
        cout << A * B << endl;
    }
    if (X == 4)
    {
        cout << A / B << endl;
    }
    if (X < 1 || X > 4)
    {
        cout << "ERRO" << endl;
    }

    return 0;
}