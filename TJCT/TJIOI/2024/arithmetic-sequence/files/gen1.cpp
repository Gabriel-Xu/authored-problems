#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int nearest(int x, int r, int d) {
    int a=x-(x%d-r+(x%d>=r?0:d));
    int b=x+(r-x%d+(r>=x%d?0:d));
    if(a>1000000000||b>=-1000000000&&x-a<=b-x) return a;
    return b;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int d=atoi(argv[1]);
    int m=atoi(argv[2]);
    vector<int> a;
    int cur=100000;
    vector<int> lens(m);
    for(int i=0; i<m; i++) {
        lens[i]=rnd.next(0, cur);
        cur-=lens[i];
    }
    shuffle(lens.begin(), lens.end(), random_device());
    for(int i=0; i<m; i++) {
        int len=lens[i];
        while(len) {
            int l=nearest(rnd.next(-1000000000, 1000000000), i, d);
            int r=nearest(rnd.next(l, 1000000000), i, d);
            int cnt=rnd.next(1, len);
            for(int j=0; j<cnt; j++) {
                a.push_back(nearest(rnd.next(l, r), i, d));
            }
            len-=cnt;
        }
    }
    cout << a.size() << " " << d << " " << m << "\n";
    println(a);
}
