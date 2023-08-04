#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    char *vetor1 = new char[100];
    char *vetor2 = new char[100];

    cin.getline(vetor1, 100);
    cin.getline(vetor2, 100);

    int tam1 = strlen(vetor1);
    int tam2 = strlen(vetor2);

    int capacidade = tam1 + tam2;
    char *vetorResultante = new char[capacidade];

    copy(vetor1, vetor1 + tam1, vetorResultante);
    vetorResultante[tam1] = ' ';
    copy(vetor2, vetor2 + tam2, vetorResultante + tam1 + 1);
    
    for (int i = 0; i < tam1 + tam2 + 1; i++) {
        cout << vetorResultante[i];
    }
    

    return 0;
}