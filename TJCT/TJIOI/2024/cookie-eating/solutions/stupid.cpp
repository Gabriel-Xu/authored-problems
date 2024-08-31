#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, c; cin >> n >> m  >> c;
    
    while (true) {
        if (c <= n) {
            cout << "Cookie Monster" << endl;
            return 0;
        }
        c -= n;
        if (c <= m) {
            cout << "Elmo" << endl;
            return 0;
        }
        c -= m;
    }
}
