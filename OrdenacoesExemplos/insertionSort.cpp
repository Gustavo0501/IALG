#include <iostream>

using namespace std;

void ordenaVetor(int vetor[], int tam) {
    int valor_pivo, j;
    for (int i = 1; i < tam; i++) {
        valor_pivo = vetor[i];
        j = i - 1;
        while ((j >= 0) and (valor_pivo < vetor[j])){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = valor_pivo;
    }

}

int main() {
    int vetor[7] = {12, 4, 6, 24, 2, 8, 9};

    ordenaVetor(vetor, 7);

    for (int i = 0; i < 7; i++) {
        cout << vetor[i] << " ";
    }
    

    return 0;
}