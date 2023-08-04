#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    int h, angulo;
    float x, y;

    cin >> h >> x >> y;

    if (h > 360)
    {
        angulo = h % 360;
    }
    else
    {
        angulo = h;
    }

    if (angulo <= 90)
    {
        cout << setprecision(1) << fixed << x + y << endl;
    }
    else if (angulo <= 180)
    {
        cout << setprecision(1) << fixed << x * y << endl;
    }
    else if (angulo <= 270)
    {
        cout << setprecision(1) << fixed << x / y << endl;
    }
    else if (angulo <= 360)
    {
        cout << setprecision(1) << fixed << pow(x, y) << endl;
    }

    return 0;
}