#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int tc; cin >> tc;
    while(tc--) {
    	string a, b; cin >> a >> b;
    	assert(a[0] != '0' && b[0] != '0');
    
    	int n = a.size();
    
    	reverse(a.begin(), a.end());
    	reverse(b.begin(), b.end());
    	while (b.size() < n - 4) b += '0';
    
    	// if (b.size() > n - 4) {
    	// 	long long ans = (__int128)n * (n-1) * (n-2) * (n-3) / 24;
    	// 	cout << ans << endl;
    	// 	return 0;
    	// }
    
    	long long dp[n+1][5][2];
    	memset(dp, 0, sizeof(dp));
    	dp[0][0][0] = 1;
    	for (int i = 1; i <= n; i++) {
    		for (int j = 0; j < 5; j++) {
    			if (j > 0) {
    				// use skip
    				dp[i][j][0] += dp[i-1][j-1][0];
    				dp[i][j][1] += dp[i-1][j-1][1];
    			}
    			int ip = i - j - 1;
    			if (ip < 0 || ip >= b.size()) continue;
    			if (a[i-1] < b[ip]) {
    				dp[i][j][1] += dp[i-1][j][0] + dp[i-1][j][1];
    			} else if (a[i-1] == b[ip]) {
    				dp[i][j][0] += dp[i-1][j][0];
    				dp[i][j][1] += dp[i-1][j][1];
    			} else {
    				dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j][1];
    			}
    
    		}
    	}
    	cout << dp[n][4][1] << endl;
    }
}
