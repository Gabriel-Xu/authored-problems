#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int c=rnd.next(1, 1000000000);
    int n=rnd.next(1, c-1);
    int m=rnd.next(1, c-n);
    cout << n << " " << m << " " << c << "\n";
}
