#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, i, a, b, cont = 0;
    float aux;
    bool capicua = true;

    cin >> n;
    
    aux = floor(n/2);

    int vet[n];

    for(i = 0; i < n; i++) {
        cin >> vet[i];
    }

    a = 0;
    b = n -1;
    i = 0;

    while (capicua && i < aux) {
        if (vet[a] == vet[b]) {
            cout << a << " " << vet[a] << " ";
            cout << b << " " << vet[b] << " ";
            cont++;
        }
        else {
            capicua = false;
        }
        a++;
        b--;
        i++;
    }

    cout << endl;
    
    if (cont == aux) {
        cout << "sim" << endl;
    }
    else {
        cout << "nao" << endl;
    }
    
    return 0;
}