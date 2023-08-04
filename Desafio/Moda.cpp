#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream arqEntrada ("valores1.txt");

    if(arqEntrada) {

    int tamanho;
    arqEntrada >> tamanho;

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        arqEntrada >> vetor[i];
    }

    int cont[tamanho] = {0};

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (vetor[i] == vetor[j]) {
                cont[i]++;
            }
        }
    }

    int freq = 0;

    for (int i = 0; i < tamanho; i++) {
        if (freq < cont[i]) {
            freq = cont[i];
        }
    }

    int armazenado[tamanho];
    int a = 0, cont1 = 0;
    armazenado[0] = -1;

    if (freq == 1) {
        cout << "Amodal" << endl;
    }
    else {
        for (int i = 0; i < tamanho; i++) {
            if (freq == cont[i]){
                for (int j = 0; j < a+1; j++) {
                    if (vetor[i] != armazenado[j]) {
                        cont1++;
                    }
                }
                if (cont1 == a+1) {
                    cout << vetor[i] << " ";
                    armazenado[a] = vetor[i];
                    a++;    
                }

                cont1 = 0;
                    
            }
        }
    }
        
    }

    arqEntrada.close();

    return 0;
}