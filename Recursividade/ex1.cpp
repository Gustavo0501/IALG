#include <iostream>

using namespace std;

int log (int n, int divs) {
    if (n % 3 != 0) {
        return divs;
    }
    else {
        divs++;
        return log(n / 3, divs);
    }
    
}

int main() {
    int n;
    cin >> n;

    int divs = 0;
    cout << log(n, divs) << endl;

    return 0;
}