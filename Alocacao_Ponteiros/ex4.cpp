#include <iostream>
#include <iomanip>

using namespace std;

struct Tempo {
    float t;
};


int main() {
    Tempo *tempos = new Tempo[8];

    float melhor;
    cin >> tempos[0].t;
    melhor = tempos[0].t;
    
    for (int i = 1; i < 8; i++) {
        cin >> tempos[i].t;

        if (tempos[i].t < melhor) {
            melhor = tempos[i].t;
        }
        
    }

    for (int i = 0; i < 8; i++) {
        if (tempos[i].t != melhor) {
            cout << setprecision(1) << fixed << tempos[i].t - melhor << endl;
        }
        else {
            cout << tempos[i].t << endl;
        }
        
    }
    
    delete [] tempos;

    return 0;
}