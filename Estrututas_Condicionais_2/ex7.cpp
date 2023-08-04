#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int codigo, pais;
    float peso, precoBruto, imposto, precoTotal;

    cin >> codigo >> peso >> pais;

    cout << setprecision(1);

    cout << fixed << (peso * 1000) << endl;

    switch (pais) {
        case 1:
        if (codigo >= 1 && codigo <= 4) {
            imposto = 0;
            precoBruto = (peso * 1000) * 10;
            precoTotal = precoBruto + imposto;
            cout << fixed << precoBruto << endl << imposto << endl << precoTotal << endl;
        }
        else if (codigo >= 5 && codigo <= 7) {
            imposto = 0;
            precoBruto = (peso * 1000) * 25;
            precoTotal = precoBruto + imposto;
            cout << fixed << precoBruto << endl << imposto << endl << precoTotal << endl;
        }
        else if (codigo >= 8) {
            imposto = 0;
            precoBruto = (peso * 1000) * 35;
            precoTotal = precoBruto + imposto;
            cout << fixed << precoBruto << endl << imposto << endl << precoTotal << endl;
        }
        break;

        case 2: 
        if (codigo >= 1 && codigo <= 4) {
            precoBruto = (peso * 1000) * 10;
            imposto = precoBruto * 0.15;
            precoTotal = precoBruto + imposto;
            cout << fixed << precoBruto << endl << imposto << endl << precoTotal << endl;
        }
        else if (codigo >= 5 && codigo <= 7) {
            precoBruto = (peso * 1000) * 25;
            imposto = precoBruto * 0.15;
            precoTotal = precoBruto + imposto;
            cout << fixed << precoBruto << endl << imposto << endl << precoTotal << endl;
        }
        else if (codigo >= 8) {
            precoBruto = (peso * 1000) * 35;
            imposto = precoBruto * 0.15;
            precoTotal = precoBruto + imposto;
            cout << fixed << precoBruto << endl << imposto << endl << precoTotal << endl;
        }
        break;

        case 3:
        if (codigo >= 1 && codigo <= 4) {
            precoBruto = (peso * 1000) * 10;
            imposto = precoBruto * 0.25;
            precoTotal = precoBruto + imposto;
            cout << fixed << precoBruto << endl << imposto << endl << precoTotal << endl;
        }
        else if (codigo >= 5 && codigo <= 7) {
            precoBruto = (peso * 1000) * 25;
            imposto = precoBruto * 0.25;
            precoTotal = precoBruto + imposto;
            cout << fixed << precoBruto << endl << imposto << endl << precoTotal << endl;
        }
        else if (codigo >= 8) {
            precoBruto = (peso * 1000) * 35;
            imposto = precoBruto * 0.25;
            precoTotal = precoBruto + imposto;
            cout << fixed << precoBruto << endl << imposto << endl << precoTotal << endl;
        }
        break;
    }

    return 0;
}