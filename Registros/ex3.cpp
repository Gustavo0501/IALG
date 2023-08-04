#include <iostream>

using namespace std;

struct cartinhas {
    string nomeCrianca, brinquedo;
};

struct brinquedos {
    string nomeBrinquedo;
    int quantidadeDisponivel, quantidadePedida;
};


int main() {
    int quantidadeCartas;
    cin >> quantidadeCartas;

    cartinhas cartinha[quantidadeCartas];

    for (int i = 0; i < quantidadeCartas; i++) {
        cin >> cartinha[i].nomeCrianca >> cartinha[i].brinquedo;
    }

    int quantidadeBrinquedos;
    cin >> quantidadeBrinquedos;

    brinquedos brinquedo[quantidadeBrinquedos];

    for (int i = 0; i < quantidadeBrinquedos; i++) {
        cin >> brinquedo[i].nomeBrinquedo >> brinquedo[i].quantidadeDisponivel;
        brinquedo[i].quantidadePedida = 0;
    }

    

    for (int i = 0; i < quantidadeCartas; i++) {
        for (int j = 0; j < quantidadeBrinquedos; j++) {
            if (cartinha[i].brinquedo == brinquedo[j].nomeBrinquedo) {
                brinquedo[j].quantidadePedida ++;
            }
            
        }
        
    }

    for (int i = 0; i < quantidadeBrinquedos; i++) {
        if (brinquedo[i].quantidadeDisponivel < brinquedo[i].quantidadePedida) {
            cout << brinquedo[i].nomeBrinquedo << " ";
        }
        
    }

    cout << endl;
    
    
    
    

    return 0;
}