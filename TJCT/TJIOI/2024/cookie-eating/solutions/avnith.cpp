#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, c; cin >> n >> m >> c; 
    c--;
    c %= n + m;
    if (c < n) cout << "Cookie Monster" << endl;
    else cout << "Elmo" << endl;
}
