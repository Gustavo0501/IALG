#include <iostream>

using namespace std;

int main() {
    int tamanhoA, tamanhoB, i, a, b, c;

    cin >> tamanhoA; 

    int vetA[tamanhoA];

    for (i = 0; i < tamanhoA; i++) {
        cin >> vetA[i];
    }

    cin >> tamanhoB;
    
    int vetB[tamanhoB];

    for(i = 0; i <tamanhoB; i++) {
        cin >> vetB[i];
    }

    int vetC[tamanhoA + tamanhoB];
    
    i = 0;
    a = 0;
    b = 0;
    c = 0;
    int cont = 0;
    bool nAcabou = true;

    while(nAcabou) {
        if (a == tamanhoA) {
            for (int j = i; j < (tamanhoB - tamanhoA); j++){
                vetC[c] = vetB[j];
                cont++;
            } 
            nAcabou = false;
        }
        else if (b == tamanhoB) {
            for (int j = i; j < (tamanhoA - tamanhoB); j++){
                vetC[c] = vetA[j];
                cont++;
            } 
            nAcabou = false;
        }
        if (vetA[i] == vetB[i]) {
            vetC[c] = vetA[i];
            i++;
            cont++;
            a++;
            b++;
            c++;
        }
        else {
            vetC[c] = vetA[i];
            vetC[c+1] = vetB[i];
            c+= 2;
            i++;
            cont += 2;
            a++;
            b++;
        }
    
    }

    for (i = 0; i < cont; i++) {
        cout << vetC[i] << " ";
    }

    return 0;
}

/*
1 2 3 4 5 == tamanho 5 
6 7 8 == tamanho 3




*/