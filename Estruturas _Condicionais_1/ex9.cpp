#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
    int xj = 0, yj = 0, x1, y1, x2, y2, x3, y3;
    string local1, local2, local3;

    cin >> x1 >> y1 >> local1 >> x2 >> y2 >> local2 >> x3 >> y3 >> local3;

    float distJ_L1, distL1_L2, distL2_L3;

    distJ_L1 = sqrt(pow(float((x1 - xj)), 2) + pow((y1 - yj), 2));
    distL1_L2 = sqrt(pow(float((x2 - x1)), 2) + pow((y2 - y1), 2));
    distL2_L3 = sqrt(pow(float((x3 - x2)), 2) + pow((y3 - y2), 2));

    float bicicleta = 0.0, carro = 0.0;

    if (local1 == "livre")
    {
        bicicleta += float(distJ_L1 * 15.0);
        carro += float(distJ_L1 * 5.0); // 18
    }
    else
    {
        bicicleta += float(distJ_L1 * 18.0);
        carro += float(distJ_L1 * 24.0);
    }

    if (local2 == "livre")
    {
        bicicleta += float(distL1_L2 * 15.0);
        carro += float(distL1_L2 * 5.0);
    }
    else
    {
        bicicleta += float(distL1_L2 * 18.0);
        carro += float(distL1_L2 * 24.0); // 53.52 = 54
    }

    if (local3 == "livre")
    {
        bicicleta += float(distL2_L3 * 15.0);
        carro += float(distL2_L3 * 5.0); // 7
    }
    else
    {
        bicicleta += float(distL2_L3 * 18.0);
        carro += float(distL2_L3 * 24.0);
    }

    if (bicicleta < carro)
    {
        cout << "Bicicleta " << ceil(bicicleta) << endl;
    }
    else
    {
        cout << "Carro " << ceil(carro) << endl;
    }

    return 0;
}