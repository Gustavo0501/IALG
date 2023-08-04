#include <iostream>

using namespace std;

struct jedis {
    string nome, hierarquia, cristal, cor;
};

struct ordemHierarquias {
    string posicao;
    int quantidade;
};



int main() {
    int quantidadeJedis;
    cin >> quantidadeJedis;

    jedis jedi[quantidadeJedis];

    ordemHierarquias hierarquias[3];
    int h = 0, cont = 0;

    for (int i = 0; i < quantidadeJedis; i++) {
        cin >> jedi[i].nome >> jedi[i].hierarquia >> jedi[i].cristal >> jedi[i].cor;
        
        for (int j = 0; j < 3; j++) {
            if (jedi[i].hierarquia != hierarquias[j].posicao){
                cont++;
            }
        }    
        if (cont == 3) {
            hierarquias[h].posicao = jedi[i].hierarquia;
            h++;
        }
        cont = 0;
    }

    string corBuscada;
    cin >> corBuscada;

    hierarquias[0].quantidade = 0;
    hierarquias[1].quantidade = 0;
    hierarquias[2].quantidade = 0;

    for (int i = 0; i < quantidadeJedis; i++) {
        if (corBuscada == jedi[i].cor) {
            if (jedi[i].hierarquia == hierarquias[0].posicao) {
                hierarquias[0].quantidade++;
            }
            else if (jedi[i].hierarquia == hierarquias[1].posicao) {
                hierarquias[1].quantidade++;
            }
            else if (jedi[i].hierarquia == hierarquias[2].posicao) {
                hierarquias[2].quantidade++;
            }   
            
        }
        
    }

    for (int i = 0; i < 3; i++) {
        cout << hierarquias[i].posicao << " " << hierarquias[i].quantidade << endl;
    }


    return 0;
}