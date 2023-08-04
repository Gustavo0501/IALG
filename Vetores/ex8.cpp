#include <iostream>

using namespace std;

void aumentoSalario (string nomes[], float salario[], int tempo[], int tamanho) {
    string comAjuste[5], semAjuste[5];
    float salarioComAjuste[5];
    int CA = 0, SA = 0;
    for (int i = 0; i < tamanho; i++) {
        if (tempo[i] >= 5 and salario[i] <= 400) {
            comAjuste[CA] = nomes[i];
            salarioComAjuste[CA] = salario[i] * 1.35;
            CA++;
        }
        else if (tempo[i] >= 5) {
            comAjuste[CA] = nomes[i];
            salarioComAjuste[CA] = salario[i] * 1.25;
            CA++;
        }
        else if (salario[i] <= 400) {
            comAjuste[CA] = nomes[i];
            salarioComAjuste[CA] = salario[i] * 1.15;
            CA++;
        }
        else {
            semAjuste[SA] = nomes[i];
            SA++;
        }
        
    }

    cout << "SEM REAJUSTE: " << endl;
    for (int i = 0; i < SA; i++) {
        cout << semAjuste[i] << endl;
    }

    cout << endl;

    cout << "COM REAJUSTE: " << endl;
    for (int i = 0; i < CA; i++) {
        cout << comAjuste[i] << " " << salarioComAjuste[i] << endl;
    }
    
    
    
}

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

    aumentoSalario(nomeFuncionarios, salario, tempoServico, 5);



    return 0;
}
