#include <iostream>

using namespace std;

int main() {
    int qtd;
    cin >> qtd;
    
    int inimigos[qtd];

    for (int i = 0; i < qtd; i++) {
        cin >> inimigos[i];
    }

    int magia = 1;
    int cont = 0;

    while (magia > 0){
        magia--;
        for (int i = 0; i < qtd; i++) {
            if (inimigos[i] != 0) {
                inimigos[i]--;
                if (inimigos[i] == 0) {
                    magia = 1;
                    cont++;
                }
                
            }
            
        }
        
    }
    
    cout << cont << endl;

    return 0;
}