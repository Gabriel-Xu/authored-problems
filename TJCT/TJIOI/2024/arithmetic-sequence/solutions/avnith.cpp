#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, m; cin >> n >> d >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int rem = arr[i] % d;
        int b = (arr[i]-rem)/d;
        if (!mp.count(rem)) mp[rem] = vector<int>();
        mp[rem].push_back(b);
    }
    
    int ans = 0;
    for (auto x : mp) {
        vector<int> v = x.second;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        
        int l = v.size();
        for (int i = l-1; i >= 0; i--) {
            if (l - i == m) {
                l--;
                ans++;
            } 
            if (i > 0 && v[i-1]+1 < v[i]) l=i;
        }
    }
    
    cout << ans << endl;
    
}
