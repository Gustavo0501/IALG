#include <iostream>

using namespace std;

int main() {
    string nomeFuncionarios[5];
    float salario[5];
    int tempoServico[5];

    for (int i = 0; i < 5; i++) {
        cin >> nomeFuncionarios[i];
    }
    for (int i = 0; i < 5; i++) {
        cin >> salario[i];
    }
    for (int i = 0; i < 5; i++) {
        cin >> tempoServico[i];
    }

    string comAjuste[5], semAjuste[5];
    float salarioComAjuste[5];
    int CA = 0, SA = 0;
    for (int i = 0; i < 5; i++) {
        if (tempoServico[i] >= 5 and salario[i] <= 400) {
            comAjuste[CA] = nomeFuncionarios[i];
            salarioComAjuste[CA] = salario[i] * 1.35;
            CA++;
        }
        else if (tempoServico[i] >= 5) {
            comAjuste[CA] = nomeFuncionarios[i];
            salarioComAjuste[CA] = salario[i] * 1.25;
            CA++;
        }
        else if (salario[i] <= 400) {
            comAjuste[CA] = nomeFuncionarios[i];
            salarioComAjuste[CA] = salario[i] * 1.15;
            CA++;
        }
        else {
            semAjuste[SA] = nomeFuncionarios[i];
            SA++;
        }
        
    }

    cout << "SEM REAJUSTE:" << endl;
    if (SA != 0) {
        for (int i = 0; i < SA; i++) {
            cout << semAjuste[i] << endl;
        }
        cout << endl;
    }
    else {
        cout << endl;
    }

    cout << "COM REAJUSTE:" << endl;
    if (CA != 0) {
        for (int i = 0; i < CA; i++) {
            cout << comAjuste[i] << " " << salarioComAjuste[i] << endl;
        }
        cout << endl;
    }
    else {
        cout << endl;
    }
    return 0;
}
