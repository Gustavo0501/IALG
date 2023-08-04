#include <iostream>

using namespace std;

struct Hidrocarboneto {
    int C, H;
};

int main() {
    Hidrocarboneto *qtdHidrocarboneto = new Hidrocarboneto;

    cin >> qtdHidrocarboneto->C >> qtdHidrocarboneto->H;

    cout << (qtdHidrocarboneto->C * 12) + (qtdHidrocarboneto->H) << endl;

    return 0;
}