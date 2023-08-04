/*
(BACKES,2012) A multiplicação de dois números naturais pode ser feita através de somas sucessivas (por exemplo, 2*3=2+2+2). Crie uma função recursiva que calcule a multiplicação por somas sucessivas de dois números naturais.

Entradas:
Dois números naturais.

Saídas:
Resultado da multiplicação dos dois números.

Exemplo de Entrada:
3 5

Exemplo de Saída:
15
*/

#include <iostream>

using namespace std;

int multi (int n1, int n2) {
    if (n2==0)
    {
        return 0;
    }
    else{
        return n1+(multi(n1, n2-1));
    }
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    cout << multi(n1, n2) << endl;

    return 0;
}