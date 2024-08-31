#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int n=atoi(argv[1]);
    int chance=atoi(argv[2]);
    int t=atoi(argv[3]);
    t/=n;
    cout << t << "\n";
    while (t--) {
        int amnt=rnd.next(1, chance);
        int y=rnd.next(1, 999999998);
        int k=rnd.next(y+1, 999999999);
        int x=rnd.next(k+1, 1000000000);
        cout << n << ' ' << x << ' ' << y << ' ' << k << '\n';
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            int v=rnd.wnext(4, amnt);
            if (v==3) {
                if (rnd.next(2)) {
                    a[i]=x;
                } else {
                    a[i]=y;
                }
            } else if (v==2) {
                a[i]=rnd.next(y+1, x-1);
            } else if (v==1) {
                a[i]=rnd.next(1, 1000000000);
            } else {
                a[i]=k;
            }
        }
        println(a);
    }
}
