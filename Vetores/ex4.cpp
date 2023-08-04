#include <iostream>

using namespace std;

int main() {
    int vet[8];

    for (int i = 0; i < 8; i++) {
        cin >> vet[i];
        
        for (int j = 0; j <= i; j++) {
            if (vet[i] < vet[j]) {
                int aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }      
        
        for(int a = 0; a <= i; a++) {
            cout << vet[a] << " ";
        }
        cout << endl;
    }
    

    return 0;
}