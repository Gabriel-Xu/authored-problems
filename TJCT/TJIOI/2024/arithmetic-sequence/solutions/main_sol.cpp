#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, d, m;
    cin >> n >> d >> m;
    vector<int> a[d];
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        a[(x%d+d)%d].push_back(x);
    }
    long long ans=0;
    for(auto& v:a) {
        sort(v.begin(), v.end());
        deque<int> q;
        for(int i=0; i<v.size(); i++) {
            if(q.size()>0&&v[i]==q.back()) continue;
            if(q.size()>0&&v[i]-q.back()!=d) {
                q.clear();
            }
            q.push_back(v[i]);
            if(q.size()>m) {
                q.pop_front();
            }
            if(q.size()==m) {
                ans++;
            }
        }
    }
    cout << ans;
}
