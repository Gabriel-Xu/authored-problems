#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        bool a[n][m];
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            for (int j=0; j<m; j++) {
                a[i][j]=s[j]-'0';
            }
        }
        int dp[n][m];
        memset(dp, -1, sizeof(dp));
        dp[0][0]=0;
        for (int i=0; i<n; i++) {
            for (int j=1; j<m; j++) {
                int cur=dp[i][j];
                int prev=dp[i][j-1];
                if (prev!=-1&&a[i][j]==a[i][j-1]&&(cur==-1||prev<cur)) {
                    dp[i][j]=prev;
                }
            }
            if (i<n-1) {
                for (int j=0; j<m; j++) {
                    int cur=dp[i][j];
                    bool need_flip=!a[i+1][j];
                    int next=dp[i+1][j];
                    if (cur!=-1&&(next==-1||cur+need_flip<next)) {
                        dp[i+1][j]=cur+need_flip;
                    }
                }
            }
        }
        cout << dp[n-1][m-1] << "\n";
    }
}
