#include <iostream>

using namespace std;

struct pais {
    int qtdOuro, qtdPrata, qtdBronze;
};

int main() {
    int *ouro = new int;
    int *prata = new int;
    int *bronze = new int;

    pais *quantidades = new pais;

    cin >> *ouro >> *prata >> *bronze;
    cin >> quantidades->qtdOuro >> quantidades->qtdPrata >> quantidades->qtdBronze;

    int soma;

    soma = ((quantidades->qtdOuro) * (*ouro)) +  ((quantidades->qtdPrata) * (*prata)) + ((quantidades->qtdBronze) * (*bronze));

    cout << soma << endl;


    return 0;
}