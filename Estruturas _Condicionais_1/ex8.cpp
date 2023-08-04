#include <iostream>
#include <iomanip>
#include <locale.h>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    string categoria;
    int dias;
    float km, aluguel;

    cin >> categoria >> dias >> km;

    if (categoria == "ECONOMICO")
    {
        aluguel = (88.00 * dias) + (1.15 * km);
        cout << "R$ " << setprecision(2) << fixed << aluguel << endl;
        cout << "Carros a disposição: Fiat Uno 1.0, Fiat Mobi 1.0, Renault Kwid 1.0, VW Gol 1.0, Ford Ka 1.0, Renault Sandero 1.0, Onix Joy 1.0" << endl;
    }
    if (categoria == "INTERMEDIARIO")
    {
        aluguel = (197.00 * dias) + (1.56 * km);
        cout << "R$ " << setprecision(2) << fixed << aluguel << endl;
        cout << "Carros a disposição: HB20 1.6, VW Gol 1.6, Renault Sandero 1.0, Fiat Cronos 1.3, Onix 1.0 Turbo, Nissan Versa FAST" << endl;
    }
    if (categoria == "PRIME")
    {
        aluguel = (265.00 * dias) + (2.89 * km);
        cout << "R$ " << setprecision(2) << fixed << aluguel << endl;
        cout << "Carros a disposição: Ford Ecoesport 1.5, Renault Duster 1.6, Nissan Kicks 1.6, VW Nivus 1.6, Fiat Pulse 1.6, Chery Tiggo 3X Turbo" << endl;
    }
    if (categoria == "ESPECIAIS")
    {
        aluguel = (335.00 * dias) + (3.40 * km);
        cout << "R$ " << setprecision(2) << fixed << aluguel << endl;
        cout << "Carros a disposição: Jeep Compass 4x4 Diesel, Mitsubishi Pajero 2.4 Diesel, Mercedes C180, Toyota Corola Cross, VW Taos Highline,   Mitsubishi Eclipse Cross" << endl;
    }

    return 0;
}