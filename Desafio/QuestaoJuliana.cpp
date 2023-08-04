#include <iostream>
#include <fstream>
#define TAM 50

using namespace std;

int main() {
    ifstream arqA ("ArquivoA.txt");
    ifstream arqB ("ArquivoB.txt");
    ofstream arqC ("ArquivoC.txt");

    int vetA[TAM], vetB[TAM];
    int elementoA, elementoB;
    int i = 0, tamanhoA = 0, tamanhoB = 0;

    if (arqA && arqB) {
        while (arqA >> elementoA) {
            vetA[i] = elementoA;
            i++;
            tamanhoA++;
        }

        i = 0;

        while (arqB >> elementoB) {
            vetB[i] = elementoB;
            i++;
            tamanhoB++;
        }


        for (int i = 0; i < tamanhoB; i++) {
            for (int j = 0; j < tamanhoA; j++) {
                if (vetB[i] == vetA[j]) {
                    arqC << vetB[i] << " ";
                }
                
            }
            
        }

        arqA.close();
        arqB.close();
        arqC.close();

    }

    return 0;
}