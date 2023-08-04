#include <iostream>

using namespace std;

int main()
{
    float valor;
    int parcelas;
    char pagamento;

    cin >> valor >> pagamento;

    if (pagamento == 'P')
    {
        cin >> parcelas;
    }

    float total;

    if (pagamento == 'V')
    {
        total = valor * 0.9;
        cout << total << endl;
    }
    else
    {
        if (parcelas == 3)
        {
            total = valor;
            cout << total << endl;
            cout << (total / 3.0);
        }
        if (parcelas == 6)
        {
            total = valor * 1.05;
            cout << total << endl;
            cout << (total / 6.0);
        }
        if (parcelas == 12)
        {
            total = valor * 1.1;
            cout << total << endl;
            cout << (total / 12.0);
        }
    }
    return 0;
}