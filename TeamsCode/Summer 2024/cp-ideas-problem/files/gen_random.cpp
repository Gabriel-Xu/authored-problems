#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int n=atoi(argv[1]);
    int t=atoi(argv[2]);
    cout << t << "\n";
    for (int i=0; i<t; i++) {
        string a="", b="";
        string digits="0123456789";
        for (int i=0; i<n; i++) {
            a+=digits[rnd.next(i==0, 9)];
        }
        for (int i=0; i<n-4; i++) {
            b+=digits[rnd.next(i==0, 9)];
        }
        cout << a << " " << b << "\n";
    }
}
