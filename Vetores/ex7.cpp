#include <iostream>

using namespace std;

int main(){
    string vendedores[10];
    int totalVendas[10];
    float percentualComissao[10];
    int somaVendas = 0;

    for (int i = 0; i < 10; i++) {
        cin >> vendedores[i];
        cin >> totalVendas[i];
        cin >> percentualComissao[i];
        somaVendas += totalVendas[i];
    }
    
    float valor[10];
    float maior = 0;
    string Mvendedor;

    for (int i = 0; i < 10; i++) {
        valor[i] = (totalVendas[i] * percentualComissao[i]);
        cout << vendedores[i] << " " << valor[i] << endl;
        
        if (valor[i] > maior) {
            maior = valor[i];
            Mvendedor = vendedores[i];
        }        
    }

    cout << somaVendas << endl;
    cout << Mvendedor << " " << maior << endl;




    


    return 0;
}