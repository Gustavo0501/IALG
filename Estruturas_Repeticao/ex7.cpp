#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string nome, p, palavra;
    int cont = 0;

    cin >> nome >> p;

    ifstream arquivo (nome);
    
    while (arquivo >> palavra) {
        if (palavra == p) {
            cont++;
        }
    }

    cout << cont << endl;
    
    
    return 0;
}