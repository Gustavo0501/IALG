#include <iostream>

using namespace std;

int main() {
    int fichas, i;
    float altura, maior = 0, menor = -1, somaM = 0, somaF = 0, mediaM, mediaF, mediaT, masculino = 0, feminino = 0;
    char genero;

    cin >> fichas;

    for (i = 0; i < fichas; i++ ) {
        cin >> altura >> genero;
        if (altura >= maior) {
            maior = altura;
        }
        if (menor < 0) {
            menor = altura;
        }
        else if (altura <= menor) {
            menor = altura;
        }
        if (genero == 'm') {
            somaM += altura;
            masculino++;
        }
        else {
            somaF += altura;
            feminino++;
        }
    }
    
    if (fichas > 0) {
        cout << maior << endl;
        cout << menor << endl;
    

        if (feminino > 0) {
            mediaF = somaF / feminino;
            cout << mediaF << endl;
        }
        else {
            cout << "ERRO" << endl;
        }
        if (masculino > 0) {
            mediaM = somaM / masculino;
            cout << mediaM << endl;
        }
        else {
            cout << "ERRO" << endl;
        }

        mediaT = (somaM + somaF) / (masculino + feminino);
        cout << mediaT << endl;
    }
    return 0;
}