#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

    int qtdevoltasT, tempoinicial1e2, tempogasto1, tempogasto2;
    float V1, V2, tempovolta1, tempovolta2, T, S;

    cin >> tempoinicial1e2;
    cin >> tempovolta1;
    cin >> tempovolta2;
    cin >> qtdevoltasT;

    if (tempovolta1 != 0)
    {
        V1 = 1 / tempovolta1;
        if (tempovolta2 != 0)
        {
            V2 = 1 / tempovolta2;

            if ((V1 - V2) != 0)
            {

                T = (1 - tempoinicial1e2) / (V1 - V2);

                // fórmula para achar o tempo gasto até que haja a ultrapassagem aplicação MRU

                if (T < 0)
                    T = (-1) * T;

                // tempo sempre é positivo, valor negativo apenas indica Se saiu antes ou depois. Qto maior o tempo q o 1 colocado sair depois do retardatário, maior o tempo T para o encontro. Caso ele saia na frente, gastará menos tempo.

                S = V1 * T;

                // número de voltas ate o 1 colocado ter 1 volta a mais q o retardatario

                S = ceil(S);

                if (S <= qtdevoltasT)
                    cout << S << endl;

                // colocar entre chaves e fechar antes do else. aqui  verificamos se a quantidade de voltas S encontrada é menor que o número de voltas do circuito, pois há uma faixa de tempo tanto se o 1 colocado sair primeiro quanto se sair depois em que haverá a ultrapassagem, maior q essa faixa de tempo, ontem um S maior q o número de voltas do circuito
            }
        }
    }
    else
        cout << "-1";

    // aqui usei a mesma variável mas agora recebendo novo valor q é o número de voltas a mais do primeiro para o segundo

    tempogasto1 = qtdevoltasT * tempovolta1;
    tempogasto2 = qtdevoltasT * tempovolta2;
    S = (tempogasto2 - tempogasto1) / qtdevoltasT;

    S = ceil(S);
    cout << S << endl;

    return 0;
}