/*
Faça um programa que recebe um vetor V de N elementos e determina, de forma recursiva, o menor elemento do vetor. Podemos usar a seguinte ideia:

O menor elemento de um vetor de uma única posição é o seu único elemento.
O menor elemento de um vetor de mais de uma posição é o menor entre o primeiro elemento e o menor do restante do vetor.

Entradas:
Tamanho N do vetor.
Elementos do vetor.

Saídas
Menor elemento do vetor.
Exemplos de Entradas e Saídas:

Entradas:
4
2 4 3 1

Saídas:
1
*/

#include <iostream>

using namespace std;

int determinarMenor (int vetor[], int n, int menor) {
    if (n < 0) {
        return menor;
    }
    else if (vetor[n-1] < menor) {
        menor = vetor[n-1];
        return determinarMenor(vetor, n-1, menor);
    }
    else {
        return determinarMenor(vetor, n-1, menor);
    }
    

}

int main() {
    int n;
    cin >> n;
    
    int vetor[n];

    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    }
    
    int menor = vetor[0];
    
    cout << determinarMenor(vetor, n, menor) << endl;
    

    return 0;
}