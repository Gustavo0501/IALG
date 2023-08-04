#include <iostream>

using namespace std;

int main() {
    float temp[12];
    int cont1 = 0, cont2 = 0, maior, menor, m1 = 0, m2 = 0;

    for (int i = 0; i < 12; i++) {
        cin >> temp[i];
    }
    
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if(temp[i] > temp[j]) {
                cont1++;
            }
            if(temp[i] < temp[j]) {
                cont2++;
            }
        }
        if (cont1 == 11) {
            maior = m1;
        }
        else {
            m1++;
        }
        if (cont2 == 11) {
            menor = m2;
        }
        else {
            m2++;
        }
        cont1 = 0;
        cont2 = 0;
    }
    
    for (int i = 0; i < 2; i++) {
        switch (maior) {
        case 0:
            cout << "janeiro" << endl;
            break;
        case 1:
            cout << "fevereiro" << endl;
            break;
        case 2:
            cout << "marco" << endl;
            break;
        case 3:
            cout << "abril" << endl;
            break;
        case 4:
            cout << "maio" << endl;
            break;
        case 5:
            cout << "junho" << endl;
            break;
        case 6:
            cout << "julho" << endl;
            break;
        case 7:
            cout << "agosto" << endl;
            break;
        case 8:
            cout << "setembro" << endl;
            break;
        case 9:
            cout << "outubro" << endl;
            break;
        case 10:
            cout << "novembro" << endl;
            break;
        case 11:
            cout << "dezembro" << endl;
            break;
        
        default:
            break;
        }
        maior = menor;
    }
    
    
    
    return 0;
}