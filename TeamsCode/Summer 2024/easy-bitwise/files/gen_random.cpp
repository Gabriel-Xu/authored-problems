#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=atoi(argv[1]);
    int t=atoi(argv[2]);
    cout << t << "\n";
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        a[i]=rnd.next(1, 1000000000);
    }
    cout << n << "\n";
    println(a);
    for (int tc=1; tc<t; tc++) {
        int n=rnd.next(2, 100);
        a.resize(n);
        for(int i=0; i<n; i++) {
            a[i]=rnd.next(1, 1000000000);
        }
        cout << n << "\n";
        println(a);
    }
}
