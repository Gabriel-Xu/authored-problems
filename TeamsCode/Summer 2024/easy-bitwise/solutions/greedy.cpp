#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n + 1];
    int sum = 0, ans = 1e18;
    for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i < n; i++){
        ans = min(ans, sum - a[i] - a[i + 1] + (a[i] ^ a[i + 1]));
    }
    cout << ans << endl;
}
 
signed main()
{
    int t; cin >> t;
    while(t--){
        solve();
    }
}
