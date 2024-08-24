#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    vector<int> a(3);
    for(int i=0; i<3; i++) a[i]=rnd.next(1, 1000000000);
    println(a);
}
