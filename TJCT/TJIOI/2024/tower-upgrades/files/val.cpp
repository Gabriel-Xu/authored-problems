#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;

struct DSU {
    vector<int> e;
    DSU(int n) : e(n, -1) {}
    int get(int x) { return (e[x] < 0 ? x : e[x] = get(e[x])); }
    bool unite(int u, int v) {
        u = get(u); v = get(v);
        if (u == v) return false;
        if (e[u] > e[v]) swap(u, v);
        e[u] += e[v]; e[v] = u;
        return true;
    }
};
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
 
    int n = inf.readInt(1, 200'000, "n");
    inf.readSpace();
    int h = inf.readInt(1, 1'000'000, "h");
    inf.readEoln();
    inf.readInts(n, 1, 1'000'000, "ci");
    inf.readEoln();
    
    DSU dsu(n);
    for (int i = 0; i < n-1; i++) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readEoln();
        u--; v--;
        dsu.unite(u, v);
    }
    
    ensuref(-dsu.e[dsu.get(0)] == n, "bro is not a tree");
    inf.readEof();
    
}
