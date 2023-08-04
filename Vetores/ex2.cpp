#include <iostream>

using namespace std;

int main() {
    int n, i, j, cont = 0;

    cin >> n;
    
    int vet[n];

    for(i = 0; i < n; i++) {
        cin >> vet[i];
    }

    for(i = 0; i < (n/2); i++) {
        for(j = (n-1); j >= (n/2); j--){
            cout << i << " " << vet[i] << " ";
            cout << j << " " << vet[j] << " ";
            /*if (vet[i] == vet[j]) {
                cont++;
            }*/
        }

    }
    /*if (cont == (n / 2)) {
        cout << "sim" << endl;
    }
    else {
        cout << "nao" << endl;
    }*/
    
    return 0;
}