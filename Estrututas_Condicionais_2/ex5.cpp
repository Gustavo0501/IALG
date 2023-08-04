#include <iostream>

using namespace std;

int main()
{
    int n1, n2, n3, nq;

    cin >> n1 >> n2 >> n3 >> nq;

    if (nq <= n1)
    {
        cout << nq << " " << n1 << " " << n2 << " " << n3 << endl;
    }
    else if (nq <= n2)
    {
        cout << n1 << " " << nq << " " << n2 << " " << n3 << endl;
    }
    else if (nq <= n3)
    {
        cout << n1 << " " << n2 << " " << nq << " " << n3 << endl;
    }
    else if (nq > n3)
    {
        cout << n1 << " " << n2 << " " << n3 << " " << nq << endl;
    }

    return 0;
}