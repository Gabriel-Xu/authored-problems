#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=atoi(argv[1]);
    int m=atoi(argv[2]);
    int t=1000000, t2=0;
    int n2=200, m2=200;
    if (n>100||m>100) {
        t2=10;
    }
    t-=t2*n2*m2;
    t/=n*m;
    cout << t+t2 << "\n";
    while (t2--) {
        cout << n2 << " " << m2 << "\n";
        for (int i=0; i<n2; i++) {
            string s="";
            for (int j=0; j<m2; j++) {
                if (i==0&&j==0) s+='1';
                else s+="01"[rnd.next(0, 1)];
            }
            cout << s << "\n";
        }
    }
    while (t--) {
        cout << n << " " << m << "\n";
        for (int i=0; i<n; i++) {
            string s="";
            for (int j=0; j<m; j++) {
                if (i==0&&j==0) s+='1';
                else s+="01"[rnd.next(0, 1)];
            }
            cout << s << "\n";
        }
    }
}
