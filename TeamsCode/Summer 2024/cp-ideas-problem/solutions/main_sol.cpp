#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int tc; cin >> tc;
    while (tc--) {
        string a, b; cin >> a >> b;
        int n=a.size();
        long long ans=0;
        vector<long long> ways(5, 0);
        ways[0]=1;
        for (int i=0; i<n; i++) {
            for (int j=4; j>=0; j--) {
                if (ways[j]>0) {
                    if (b[i-j]>a[i]) {
                        if (4-j<=n-i-1) {
                            long long count=ways[j];
                            for (int x=1; x<=4-j; x++) {
                                count*=n-i-x;
                            }
                            for (int x=2; x<=4-j; x++) {
                                count/=x;
                            }
                            ans+=count;
                        }
                    }
                    if (j!=4) {
                        ways[j+1]+=ways[j];
                    }
                    if (b[i-j]!=a[i]) {
                        ways[j]=0;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
