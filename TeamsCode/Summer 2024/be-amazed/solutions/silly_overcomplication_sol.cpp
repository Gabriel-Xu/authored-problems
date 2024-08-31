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
        int dp[n][m][2]; // row, column, flipped or not
        memset(dp, -1, sizeof(dp));
        dp[0][0][0]=0;
        for (int i=0; i<n; i++) {
            for (int flip=0; flip<2; flip++) {
                for (int j=1; j<m; j++) {
                    int cur=dp[i][j][flip];
                    int prev=dp[i][j-1][flip];
                    if (prev!=-1&&a[i][j]==a[i][j-1]&&(cur==-1||prev<cur)) {
                        dp[i][j][flip]=prev;
                    }
                }
                if (i<n-1) {
                    for (int j=0; j<m; j++) {
                        int cur=dp[i][j][flip];
                        bool diff=a[i][j]!=a[i+1][j];
                        bool need_flip=flip^diff;
                        int next=dp[i+1][j][a[i][j]^flip];
                        if (cur!=-1&&(next==-1||cur+need_flip<next)) {
                            dp[i+1][j][a[i][j]^flip]=cur+need_flip;
                        }
                    }
                }
            }
        }
        int ans=-1;
        for (int i=0; i<2; i++) {
            int val=dp[n-1][m-1][i];
            if (ans==-1||val<ans&&val!=-1) {
                ans=val;
            }
        }
        cout << ans << "\n";
    }
}
