#include "testlib.h"
using namespace std;

int main(int argc, char**argv) {
    registerValidation(argc, argv);
    int n=inf.readInt(1, 100'000, "n");
    inf.readEoln();
    vector<bool> used(2*n+1, 0);
    int minv=1;
    for (int i=0; i<n; i++) {
        int t=inf.readInt(1, 3, "t");
        inf.readSpace();
        int v=inf.readInt(1, 4*n-1, "v");
        inf.readEoln();
        if (t==1) v-=minv;
        else if (t==2) v+=minv;
        ensure(used[v]==false);
        used[v]=true;
        ensure(used[minv]==false);
        used[minv]=true;
        while (used[minv]) minv++;
    }
    inf.readEof();
}
