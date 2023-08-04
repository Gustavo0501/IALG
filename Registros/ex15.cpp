#include <iostream>

using namespace std;

struct dadosPlaneta {
    int stormtroopers;
    int batalhas;
};


struct dadosStormtrooper {
    string nome;
    string planetaOrigem;
    int batalhas;
};


int main() {
    int tamanho;
    cin >> tamanho;

    dadosStormtrooper stormtrooper[tamanho];
    string nomesPlanetas[tamanho];
    int cont = 0;
    int tam = 0;

    for (int i = 0; i < tamanho; i++) {
        cin >> stormtrooper[i].nome >> stormtrooper[i].planetaOrigem >> stormtrooper[i].batalhas;

        for (int j = 0; j < i; j++) {
            if (stormtrooper[i].planetaOrigem == nomesPlanetas[j]) {
                cont++;
            }    
        }
        if (cont == 0) {
            nomesPlanetas[tam] = stormtrooper[i].planetaOrigem;
            tam++;
        }
        
        cont = 0;
        
    }

    dadosPlaneta planeta[tam];

    for (int i = 0; i < tam; i++) {
        planeta[i].batalhas = 0;
        planeta[i].stormtroopers = 0;
    }
    
    
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tam; j++) {
            if (stormtrooper[i].planetaOrigem == nomesPlanetas[j]) {
                planeta[j].stormtroopers++;
                planeta[j].batalhas += stormtrooper[i].batalhas;
            }
            
        }
        
    }
    
    for (int i = 0; i < tam; i++) {
        cout << nomesPlanetas[i] << " " << planeta[i].stormtroopers << " " << (float) planeta[i].batalhas / planeta[i].stormtroopers << endl;
    }
    
    
    return 0;
}