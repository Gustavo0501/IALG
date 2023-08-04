#include <iostream>

using namespace std;

int main()
{
    char a, b;
    int v1 = 0, v2 = 0;

    cin >> a >> b;

    v1 += a;
    v2 += b;

    if (v1 > v2)
    {
        cout << a;
    }
    else
    {
        cout << b;
    }

    return 0;
}