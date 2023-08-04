#include <iostream>
#include <cstdlib>

using namespace std;

void ordenaVetor(int vetor[], int tam) {
    int posMenor;

    for (int i = 0; i < tam-1; i++) {
        posMenor = i;
        for (int j = i+1; j < tam; j++) {
            if (vetor[j] < vetor[posMenor]) {
                posMenor = j;
            }
            
        }
        swap(vetor[i], vetor[posMenor]);
        
    }

}

int main() {
    int vetor[11] = {5, 1, 9, 3, 7, 4, 2, 0, 6, 8, 10};

    ordenaVetor(vetor, 11);

    for (int i = 0; i < 11; i++) {
        cout << vetor[i] << endl;
    }
    

    return 0;
}