#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int t=atoi(argv[1]);
    cout << t << "\n";
    for(int i=0; i<2; i++) {
        vector<int> a(t);
        for(int& x:a) {
            x=rnd.next(0, 1000000);
        }
        println(a);
    }
}
