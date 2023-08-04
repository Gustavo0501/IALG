#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Carro {
    string marca;
    int ano;
    float distancia;
    float consumo;
};

float consumoKmL (float km, float consumo) {
    float consumoFinal;

    consumoFinal = km / consumo;

    return consumoFinal;
}

int main() {
    Carro *dadosCarro = new Carro;

    ifstream arqEntrada ("entrada.txt");

    arqEntrada >> dadosCarro->marca;
    arqEntrada >> dadosCarro->ano;
    arqEntrada >> dadosCarro->distancia;
    arqEntrada >> dadosCarro->consumo;

    ofstream arqSaida ("saida.txt");

    arqSaida << dadosCarro->marca << endl << dadosCarro->ano << endl << dadosCarro->consumo << endl;
    arqSaida << consumoKmL(dadosCarro->distancia, dadosCarro->consumo) << endl;


    return 0;
}