#include <iostream>

using namespace std;

struct ponto {
    int p1, p2;
};

struct retangulo {
    ponto v1, v2;
};


int main() {
    ponto P;
    cin >> P.p1 >> P.p2;

    int quantidadeRetangulos;
    cin >> quantidadeRetangulos;

    retangulo vertice;
    int cont = 0;

    for (int i = 0; i < quantidadeRetangulos; i++) {
        cin >> vertice.v1.p1 >> vertice.v1.p2 >> vertice.v2.p1 >> vertice.v2.p2;

        if (P.p1 >= vertice.v1.p1 and P.p2 >= vertice.v1.p2 and P.p1 <= vertice.v2.p1 and P.p2 <= vertice.v2.p2) {
            cont++;
        }
        
    }

    cout << cont << endl;
    
    

    return 0;
}