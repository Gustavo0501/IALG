#include <iostream>

using namespace std;

int main(){
    int x, y, q = 0;

    cin >> x >> y;

    while ((x-y) >= 0) {
        q++;
        x -= y;
    }
    cout << q << endl;
    return 0;
}