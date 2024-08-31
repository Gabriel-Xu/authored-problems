#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define endl '\n'
using namespace std;

int n, x, y, k;
int a[500005];

int main()
{
    fast;
    int t; cin >> t;
    while(t--){
        cin >> n >> x >> y >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == k) continue;
            int mn = a[i], mx = a[i];
            for(int j = i + 1; j <= n; j++){
                if(a[j] == k) break;
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
                if(mn == y && mx == x) ans++;
                else if(mn<y||mx>x) break;
            }
        }
        cout << ans << endl;
    }
}
