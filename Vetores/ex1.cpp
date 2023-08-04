#include <iostream>

using namespace std;

int main() {
    int vet[16];
    int i = 0, cont = 0;

    for(i = 0; i<16; i++) {
        cin >> vet[i];
    }

    for(i = 14; i > 0; i--) {
        if (vet[i] != 0) {
            if (vet[i] % vet[0] == 0) {
                cout << vet[i] << " ";
            }
            else{
                cont++;
            }
        }
        else {
            cont++;
        }
    }
    if (cont >= 14) {
        cout << vet[15] << endl;
    }


    return 0;
}