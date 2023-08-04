#include <iostream>

using namespace std;

void imprimeVetor (int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;
    
}

int main() {
    int vet[7], mult2[7], mult3[7], mult2e3[7];
    int m2 = 0, m3 = 0, m2e3 = 0, cont = 0;

    for (int i = 0; i < 7; i++) {
        cin >> vet[i];
        if (vet[i] % 2 == 0) {
            mult2[m2] = vet[i];
            m2++;
        }
        if (vet[i] % 3 == 0) {
            mult3[m3] = vet[i];
            m3++;
        }
        if (vet[i] % 2 == 0 && vet[i] % 3 == 0) {
            mult2e3[m2e3] = vet[i];
            m2e3++;
        }
        if (vet[i] % 2 != 0 || vet[i] % 3 != 0) {
            cont++;
        }
    }

    if (cont == 7) {
        cout << 0 << endl;
    }
    else {
        imprimeVetor(mult2, (m2));
        imprimeVetor(mult3, (m3));
        imprimeVetor(mult2e3, (m2e3));
    }


    return 0;
}