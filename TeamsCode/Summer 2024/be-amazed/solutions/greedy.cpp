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
        int j=0;
        int ans=0;
        for (int i=0; i<n-1; i++) {
            while (j<m-1&&a[i][j]==a[i][j+1]) j++;
            if (!a[i+1][j]) ans++;
        }
        if (j==m-1) {
            cout << ans << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
