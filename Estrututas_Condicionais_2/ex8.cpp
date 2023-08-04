#include <iostream>

using namespace std;

int main() {
    float horasExtras, horasFaltas, H, minutos;

    cin >> horasExtras >> horasFaltas;

    H = horasExtras - (2/3 * (horasFaltas));
    minutos = H * 60;

    if(minutos > 2400) {
        cout << 500 << endl;
    }
    else if(minutos > 1800 && minutos <= 2400) {
        cout << 400 << endl;
    }
    else if(minutos > 1200 && minutos <=1800) {
        cout << 300 << endl;
    }
    else if(minutos > 600 && minutos <= 1200) {
        cout << 200 << endl;
    }
    else if(minutos <= 600) {
        cout << 100 << endl;
    }
    return 0;
}