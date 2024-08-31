#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long ans=1;
    int mod=1e9+7;
    vector<bool> used(2*n+1, 0);
    int maxa=0;
    int maxb=0;
    int min_unused=1;
    for (int i=0; i<n; i++) {
        if (min_unused>maxa&&min_unused>maxb) {
            ans*=2;
            ans%=mod;
        }
        int t, v; cin >> t >> v;
        if (t==1) v-=min_unused;
        else if (t==2) v+=min_unused;
        maxa=min_unused;
        maxb=v;
        used[min_unused]=true;
        used[v]=true;
        while (used[min_unused]) min_unused++;
    }
    cout << ans;
}
