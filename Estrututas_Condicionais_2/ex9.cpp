#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    char opcao, formato;
    float n;

    const long double PI = 3.1415926535897;

    cin >> opcao >> formato >> n;

    cout << setprecision(4);

    if (formato == 'g') {
        n = n * (PI/180);
    }

    if (opcao == 's') {
        cout << fixed << sin(n) << endl;
    }
    else {
        cout << fixed << cos(n) << endl;
    }
    
    return 0;
}