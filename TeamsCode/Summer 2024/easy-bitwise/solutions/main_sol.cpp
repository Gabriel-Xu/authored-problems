#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<bool> good(n);
        long long sum=0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            good[i]=true;
            sum+=a[i];
        }
        for (int shift=29; shift>=0; shift--) {
            int count=0;
            for (int i=0; i<n; i++) {
                if (good[i] && (a[i]>>shift)%2) {
                    count++;
                }
            }
            if (count>=2) {
                for (int i=0; i<n; i++) {
                    if (good[i] && (a[i]>>shift)%2==0) {
                        good[i]=false;
                    }
                }
            }
        }
        long long ans=(2>>30)-1;
        int count=0;
        for (int i=0; i<n; i++) {
            if (good[i]) {
                ans&=a[i];
                count++;
            }
            if (count==2) {
                break;
            }
        }
        cout << (sum-ans*2) << "\n";
    }
}
