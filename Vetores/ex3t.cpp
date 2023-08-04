#include <iostream>

using namespace std;

int main() {
    int tamanhoA, tamanhoB, i;

    cin >> tamanhoA; 

    int vetA[tamanhoA];

    for (i = 0; i < tamanhoA; i++) {
        cin >> vetA[i];
    }

    cin >> tamanhoB;
    
    int vetB[tamanhoB];

    for(i = 0; i <tamanhoB; i++) {
        cin >> vetB[i];
    }

    int tamanhoC = tamanhoA + tamanhoB;
    int vetC[tamanhoC];

    for (int i = 0; i < tamanhoA; i++) {
        vetC[i] = vetA[i];
    }

    for (int i = 0; i < tamanhoB; i++) {
        vetC[tamanhoA + i] = vetB[i];
    }

    for (int i = 0; i < tamanhoC; i++) {
        for (int j = i + 1; j < tamanhoC; j++) {
            if (vetC[i] > vetC[j]) {
                int aux = vetC[i];
                vetC[i] = vetC[j];
                vetC[j] = aux;
            }
            if (vetC[i] == vetC[j]) {
                vetC[j] = vetC[tamanhoC - 1];
                tamanhoC--;
                j--;
            }
        }
    }

    //==========================
    for (i = 0; i < tamanhoC; i++) {
        cout << vetC[i] << " ";
    }

    return 0;
}