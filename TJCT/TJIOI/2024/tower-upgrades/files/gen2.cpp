#include "testlib.h"
#include <iostream>
 
using namespace std;

const int n = 200'000;
vector<int> adj[n];
vector<bool> vis(n, false);
vector<int> depth(n);

void dfs(int x, int d) {
    if (vis[x]) return;
    vis[x] = true;
    depth[x] = d;
    
    for (auto y : adj[x]) dfs(y, d+1);
}
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
 
    int w1 = opt<int>(1);
    int h = opt<int>(2);
    int mx = opt<int>(3);
    double m = opt<double>(4);
    double b = opt<double>(5);
    
    // round(depth * m + b)
    
    vector<pair<int, int>> eds;
    vector<int> perm(n, 0);
    for (int i = 1; i < n; i++) {
        int u = rnd.wnext(0, i-1, w1);
        if (rnd.next(0, 1) == 0) eds.push_back({u, i});
        else eds.push_back({u, i});
        perm[i] = i;
    }
    shuffle(1+perm.begin(), perm.end());
    
    for (auto &x : eds) {
        x.first = perm[x.first];
        x.second = perm[x.second];
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }
    
    dfs(0, 0);
    
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        int ww = int(m * (double)depth[i] + b);
        c[i] = rnd.wnext(1, mx, ww);
    }
    
    cout << n << " " << h << endl;
    for (int i = 0; i < n; i++) cout << c[i] << " \n"[i==n-1];
    shuffle(eds.begin(), eds.end());
    
    for (auto x : eds) cout << x.first+1 << " " << x.second+1 << endl;

}
