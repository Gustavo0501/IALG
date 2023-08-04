/*
Faça um programa que recebe um vetor já ordenado e um número a ser procurado, o programa deverá utilizar uma busca binária recursiva que tem como retorno a posição do elemento procurado ou -1 caso não encontre o elemento.

Entradas:
Tamanho do vetor.
Elementos do vetor já ordenado.
Número a ser procurado.

Saídas:
Posição do elemento no vetor ou -1 caso não seja encontrado.

Exemplo de Entrada:
7
3 7 9 14 17 23 52
52

Exemplo de Saída:
6
*/

#include <iostream>

using namespace std;

int buscaBin (int vetor[], int inicio, int fim, int buscado) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (buscado > vetor[meio]) {
            return buscaBin(vetor, meio + 1, fim, buscado);
        }
        else if (buscado < vetor[meio]) {
            return buscaBin(vetor, inicio, meio-1, buscado);
        }
        else{
            return meio;
        }
        
    }
    
    return -1;
    
    



} 

int main() {
    int tamanho;
    cin >> tamanho;

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        cin >> vetor[i];
    }

    int buscado;
    cin >> buscado;

    cout << buscaBin(vetor, 0, tamanho-1, buscado);
    


    return 0;
}