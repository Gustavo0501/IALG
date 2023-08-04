#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string nome;
    char c;
    int cont = 0;

    cin >> nome;

    ifstream arquivo (nome);
    while (arquivo >> c) {
        cont++;
    }

    cout << cont << endl;
    
    
    return 0;
}