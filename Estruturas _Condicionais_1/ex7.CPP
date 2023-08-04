#include <iostream>

using namespace std;

int main()
{
    int tempoSepara, tempoVoltaPrimeiro, tempoVoltaUltimo, n_voltas, voltasNecessarias = 0;

    cin >> tempoSepara >> tempoVoltaPrimeiro >> tempoVoltaUltimo >> n_voltas;

    int voltaPrimeiro, voltaUltimo;

    if (tempoSepara < 0)
    {
        voltaPrimeiro = tempoVoltaPrimeiro / tempoVoltaUltimo;             // 0.25
        voltaUltimo = tempoVoltaUltimo - (tempoVoltaUltimo - tempoSepara); // 1
        tempoSepara = 0;
        voltaPrimeiro -= tempoVoltaPrimeiro / tempoVoltaUltimo;
    }

    /*if (variavel >= tempoUltimo)
    {
        cout << "Retardatario";
    }
    else
    {
        cout << "N retardario";
    }*/
    // int variavel;

    // variavel = tempoSepara * voltas;

    return 0;
}