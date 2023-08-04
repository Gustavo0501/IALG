#include <iostream>

using namespace std;

int main() {
    string cor1, cor2;
    int n, primeiro, ultimo;

    cin >> cor1 >> cor2 >> n;

    primeiro = n % 10;
    ultimo = n / 100000;

    if (primeiro == ultimo) {
        cout << cor1 << endl;
    }
    else {
        cout << cor2 << endl;
    }
    
    return 0;
}