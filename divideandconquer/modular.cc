#include <iostream>
using namespace std;

int modular(int n, int k, int m) {
    if (m == 1) return 0;
    int c = 1;
    n = n%m;
    while (k > 0) {
        if (k%2 == 1) c = (c*n)%m;
        k = k >> 1;
        n = (n*n)%m;
    }
    return c;
}

int main () {
    int n, k, m;
    while (cin >> n >> k >> m) {
        int c = modular(n, k, m);
        cout << c << endl;
    }
}
