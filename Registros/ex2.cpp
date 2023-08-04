#include <iostream>

using namespace std;

struct datas {
    int dia, mes, ano;
};

struct pessoa {
    string nome;
    datas data;
};


int main() {
    int quantidadePessoas;
    cin >> quantidadePessoas;

    pessoa dadosPessoa[quantidadePessoas];

    cin >> dadosPessoa[0].nome >> dadosPessoa[0].data.dia >> dadosPessoa[0].data.mes >> dadosPessoa[0].data.ano;

    int maisVelha = 0;

    for (int i = 1; i < quantidadePessoas; i++) {
        cin >> dadosPessoa[i].nome >> dadosPessoa[i].data.dia >> dadosPessoa[i].data.mes >> dadosPessoa[i].data.ano;

        if (dadosPessoa[i].data.ano < dadosPessoa[maisVelha].data.ano) {
            maisVelha = i;
        }
        else if (dadosPessoa[i].data.ano == dadosPessoa[maisVelha].data.ano) {
            if (dadosPessoa[i].data.mes < dadosPessoa[maisVelha].data.mes) {
                maisVelha = i;
            }
            else if (dadosPessoa[i].data.mes == dadosPessoa[maisVelha].data.mes) {
                if (dadosPessoa[i].data.dia < dadosPessoa[maisVelha].data.dia) {
                    maisVelha = i;
                }
                
            }
            
            
        }
        
        
    }

    cout << dadosPessoa[maisVelha].nome << endl;
    


    return 0;
}