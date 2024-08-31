#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int n=atoi(argv[1]);
    int low=atoi(argv[2]);
    cout << n << "\n";
    vector<bool> used(2*n+1, 0);
    int maxa=0;
    int maxb=0;
    int min_unused=1;
    for (int i=0; i<n; i++) {
        int lower=max(maxb, min_unused)+1;
        int v=lower+rnd.wnext(n+i-maxb, -low);
        int t=rnd.next(1, 3);
        cout << t << ' ';
        if (t==1) {
            cout << min_unused+v;
        } else if (t==2) {
            cout << abs(min_unused-v);
        } else {
            cout << v;
        }
        cout << "\n";
        maxa=min_unused;
        maxb=v;
        used[min_unused]=true;
        used[v]=true;
        while (used[min_unused]) min_unused++;
    }
}
