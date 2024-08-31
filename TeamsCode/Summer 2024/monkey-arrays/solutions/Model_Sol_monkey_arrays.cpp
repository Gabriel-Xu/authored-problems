#include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;

int n, X, Y, k;

long long simulate(vector <int> a){
    if(a.size() == 0) return 0;
    set <int> tot;
    int ans = 0, st = 0, ftx = 0, fty = 0;
    for(int i = 0; i < (int)a.size(); i++){
        tot.insert(a[i]);
        int x = *tot.rbegin(), y = *tot.begin(), nx = tot.count(X), ny = tot.count(Y);
        if(a[i] == X) ftx = i;
        if(a[i] == Y) fty = i;
        if(x > X){
            st = i+1;
            tot.clear(); continue;
        }
        if(y < Y){
            st = i+1;
            tot.clear(); continue;
        }
        if(a[i] == X && ny) ans += fty - st + 1;
        else if(a[i] == Y && nx) ans += ftx - st + 1;
        else if(nx && ny && a[i] != X && a[i] != Y) ans += min(fty, ftx) - st + 1;
    }
    return ans;
}

signed main()
{
    fast;
    int t; cin >> t;
    while(t--){
        cin >> n >> X >> Y >> k;
        int a[n + 1];
        for(int i = 1; i <= n; i++) cin >> a[i];
        if(Y > X){
            cout << 0 << endl;
            continue;
        }
        vector <int> push;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == k){
                ans += simulate(push);
                push.clear();
            }
            else push.push_back(a[i]);
        }
        ans += simulate(push);
        cout << ans << endl;
    }
}
