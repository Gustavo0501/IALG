#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int limiteCarga, cavalos, vacas, galinhas;

    cin >> limiteCarga >> cavalos >> vacas >> galinhas;

    int Pcavalo, Pvaca, Pgalinha;
    float Ncavalo, Nvaca, Ngalinha;

    Pcavalo = cavalos * 250;
    Pvaca = vacas * 150;
    Pgalinha = galinhas * 2;

    if (Pgalinha <= limiteCarga) {
        Ngalinha = 0;
        limiteCarga -= Pgalinha;
    }
    else {
        Ngalinha = ceil((Pgalinha - limiteCarga) / 2.0);
        limiteCarga -= (galinhas - Ngalinha) * 2;
    }
    
    
    if (Pvaca <= limiteCarga) {
        Nvaca = 0;
        limiteCarga -= Pvaca;
    }
    else {
        Nvaca = ceil((Pvaca - limiteCarga) / 150.0);
        limiteCarga -= (vacas - Nvaca) * 150;
    }
    
    
    if (Pcavalo <= limiteCarga) {
        Ncavalo= 0;
        limiteCarga -= Pcavalo;
    }
    else {
        Ncavalo = ceil((Pcavalo - limiteCarga) / 250.0);
    }

    cout << Ncavalo << endl << Nvaca << endl << Ngalinha;
    
    return 0;
}