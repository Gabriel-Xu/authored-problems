#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    int ans=0;
    for(int i=0; i<t; i++) {
        int x;
        cin >> x;
        ans+=x;
    }
    cout << ans/t << " ";
    ans=0;
    for(int i=0; i<t; i++) {
        int x;
        cin >> x;
        ans+=x;
    }
    cout << ans/t << "\n";
}
