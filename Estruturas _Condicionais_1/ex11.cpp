#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    float kg, kgdia = 0;
    string ds;

    ifstream arquivo("jazida.txt");

    arquivo >> kg;
    if (kg > kgdia)
    {
        kgdia = kg;
        ds = "domingo";
    }
    arquivo >> kg;
    if (kg > kgdia)
    {
        kgdia = kg;
        ds = "segunda-feira";
    }
    arquivo >> kg;
    if (kg > kgdia)
    {
        kgdia = kg;
        ds = "terca-feira";
    }
    arquivo >> kg;
    if (kg > kgdia)
    {
        kgdia = kg;
        ds = "quarta-feira";
    }
    arquivo >> kg;
    if (kg > kgdia)
    {
        kgdia = kg;
        ds = "quinta-feira";
    }
    arquivo >> kg;
    if (kg > kgdia)
    {
        kgdia = kg;
        ds = "sexta-feira";
    }
    arquivo >> kg;
    if (kg > kgdia)
    {
        kgdia = kg;
        ds = "sabado";
    }

    cout << ds << endl;
    cout << setprecision(1) << fixed << kgdia;
    return 0;
}