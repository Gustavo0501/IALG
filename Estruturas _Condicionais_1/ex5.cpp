#include <iostream>

using namespace std;

int main()
{
    float n1, n2, n3, n4, soma = 0;

    cin >> n1 >> n2 >> n3 >> n4;

    if (n1 <= n2 || n1 <= n3 || n1 <= n4)
    {
        soma += n1;
    }
    if (n2 <= n1 || n2 <= n3 || n2 <= n4)
    {
        soma += n2;
    }
    if (n3 <= n2 || n3 <= n1 || n3 <= n4)
    {
        soma += n3;
    }
    if ((n4 <= n2 || n4 <= n3 || n4 <= n1) && soma != n1 + n2 + n3)
    {
        soma += n4;
    }

    cout << soma << endl;

    return 0;
}