/*
A sequência de Ricci é uma sequência bastante semelhante à de Fibonacci, diferindo desta apenas pelo fato que os dois primeiros termos da sequência ( F(0) e F(1) ) devem ser definidos pelo usuário.

Sabendo-se que a sequência de Fibonacci é definida por:

F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2) , n > 2
Crie um programa que imprima os n primeiros termos da sequência de Ricci, utilizando um subprograma recursivo que retorna o n-ésimo termo da referida série.

Entrada:
Os valores iniciais da série de Ricci ( F(0) e F(1) );
Os número de termos dessa sequência a serem impressos.

Saída:
Os n termos dessa sequência.

Exemplo de entrada:
5 8
6

Exemplo de saída:
5 8 13 21 34 55
*/

#include <iostream>

using namespace std;

void ricci(int t1, int t2, int n) {
    if (n == 0) {
        return;
    }
    
    cout << t1 << " ";

    ricci(t2, t1 + t2, n - 1);
    
}

int main() {
    int t1, t2;
    cin >> t1 >> t2;

    int n;
    cin >> n;

    ricci(t1, t2, n);

    cout << endl;

    return 0;
}