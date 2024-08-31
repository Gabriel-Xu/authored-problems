#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n);
        long long sum=0;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            sum+=a[i];
        }
        int maxv=0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                maxv=max(maxv, a[i]+a[j]-(a[i]^a[j]));
            }
        }
        cout << (sum-maxv) << "\n";
    }
}
