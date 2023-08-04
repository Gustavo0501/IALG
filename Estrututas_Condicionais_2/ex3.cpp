#include <iostream>

using namespace std;

int main()
{
    float trabalhoLab, avaliacaoSemestral, exameFinal, media;

    cin >> trabalhoLab >> avaliacaoSemestral >> exameFinal;

    media = ((trabalhoLab * 2) + (avaliacaoSemestral * 3) + (exameFinal * 5)) / 10;

    if (media >= 8)
    {
        cout << media << endl;
        cout << 'A';
    }
    else if (media >= 7)
    {
        cout << media << endl;
        cout << 'B';
    }
    else if (media >= 6)
    {
        cout << media << endl;
        cout << 'C';
    }
    else if (media >= 5)
    {
        cout << media << endl;
        cout << 'D';
    }
    else if (media < 5)
    {
        cout << media << endl;
        cout << 'E';
    }

    return 0;
}