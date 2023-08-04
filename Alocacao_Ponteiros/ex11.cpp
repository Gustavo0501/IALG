#include <iostream>

using namespace std;

void aumentarVetor (int* &vetor, int &capacidade, int &cont) {
    int *temp = new int[capacidade + 5];
    
    for (int i = 0; i < capacidade; i++) {
        temp[i] = vetor[i];
    }
    
    delete [] vetor;
    vetor = temp;

    capacidade += 5;
    cont++;
}

int main() {
    int capacidade = 5;
    int cont = 0;
    int *vetor = new int[capacidade];

    int i = 0, tam = 0;

    do {
        cin >> vetor[i];
        if (i == capacidade - 1 and vetor[i] > 0){
            aumentarVetor(vetor, capacidade, cont);
        }
        i++;
        tam++;
    } while (vetor[i-1] > 0 and i < capacidade);


    for (int i = 0; i < tam -1; i++){
        cout << vetor[i] << " ";
    }
    
    cout << endl;
    cout << capacidade << endl;
    cout << cont << endl;    
    



    return 0;
}