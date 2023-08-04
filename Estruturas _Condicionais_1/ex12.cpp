#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string assassino1, assassino2, assassino3, resposta;
    int sim = 0, nao = 0;

    ifstream arquivo("investigacao.txt");

    arquivo >> assassino1 >> assassino2 >> assassino3;

    while (arquivo >> resposta)
    {
        if (resposta == "sim")
        {
            sim++;
        }
        else
        {
            nao++;
        }
    }

    if (sim < 2)
    {
        cout << assassino1 << " " << assassino2 << " " << assassino3 << endl;
    }
    else if (sim == 2)
    {
        cout << assassino1 << endl;
    }
    else if (sim == 3 || sim == 4)
    {
        cout << assassino2 << endl;
    }
    else if (sim == 5)
    {
        cout << assassino3 << endl;
    }
    return 0;
}
