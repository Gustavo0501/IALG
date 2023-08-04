#include <iostream>
#include <fstream>

using namespace std;

struct operacoes {
    int identificador;
    string nome;
};

void ordenarVetor1 (operacoes vetor[], int tam, int k) {
    int valor_pivo, j;
    string nome_pivo;
    for (int i = 1; i < k; i++) {
        valor_pivo = vetor[i].identificador;
        nome_pivo = vetor[i].nome;
        j = i - 1;
        while ((j >= 0) and (valor_pivo > vetor[j].identificador)){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1].identificador = valor_pivo;
        vetor[j+1].nome = nome_pivo;
    }


}

void ordenarVetor2 (operacoes vetor[], int tam, int k) {
    int valor_pivo, j;
    string nome_pivo;
    for (int i = k; i < tam; i++) {
        valor_pivo = vetor[i].identificador;
        nome_pivo = vetor[i].nome;
        j = i - 1;
        while ((j >= 0) and (valor_pivo < vetor[j].identificador)){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1].identificador = valor_pivo;
        vetor[j+1].nome = nome_pivo;
    }
}


int main() {
    int capacidade = 5;
    operacoes *ops = new operacoes[capacidade];
    
    ifstream arqEntrada ("fases.txt");

    int cont = 0;
    
    while (arqEntrada >> ops[cont].identificador >> ops[cont].nome) {
        cont++;
        if (cont == capacidade) {
            capacidade += 5;
            operacoes *temp = new operacoes[capacidade];
            for (int i = 0; i < cont; i++){
                temp[i] = ops[i];
            }
            delete [] ops;
            ops = temp;
        }
        
    }

    int k;
    cin >> k;

    ordenarVetor1(ops, cont, k);
    
    ordenarVetor2(ops, cont, k);
    
    
    for (int i = 0; i < cont; i++) {
        cout << ops[i].nome << endl;
    }
    
    delete [] ops;

    return 0;
}