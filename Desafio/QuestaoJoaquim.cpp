#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream arqEntrada ("valores.txt");

    if(arqEntrada) {

    int tamanho;
    arqEntrada >> tamanho;

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        arqEntrada >> vetor[i];
    }

    int maiorModa = vetor[0];
    int moda, cont1 = 0, cont2 = -1;

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (vetor[i] == vetor[j]) {
                cont1++;
            }
            
        }
        if (cont1 >= cont2) {
            moda = vetor[i];
            cont2 = cont1;
        }

        if(moda > maiorModa) {
            maiorModa = moda;
        }

        cont1 = 0;
    }

    cout << "Maior moda: " << maiorModa << endl;

    }

    arqEntrada.close();

    return 0;
}