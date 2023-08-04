#include <iostream>

using namespace std;

int main(){
    int n, soma = 0, i = -1, positivo = 0, negativo = 0;
    float media, pPositivo, pNegativo;

    do {
        cin >> n;
        soma += n;
        i++;
        if (n > 0) {
            positivo++;
        }
        else {
            negativo++;
        }
    } while (n != 0);

        

    media = float(soma) / i;
    pPositivo = float(positivo) / i;
    pNegativo = float((negativo - 1)) / i;

    cout << media << endl << positivo << endl << (negativo - 1) << endl << pPositivo << endl << pNegativo << endl;

    return 0;
}