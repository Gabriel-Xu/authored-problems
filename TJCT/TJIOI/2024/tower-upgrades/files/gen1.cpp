#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define pbds tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

void treeTCgenerator(ll numberOfNodes) {
    pbds includedInTree;
    pbds notIncludedInTree;

    ll root = 1;
    includedInTree.insert(root);
    for (ll i = 1; i <= numberOfNodes; i++) {
        if(i != root) {
            notIncludedInTree.insert(i);
        }
    }
    vector<pair<int,int>> edges;
    for (ll i = 0; i < numberOfNodes - 1; i++) {
        ll r=rnd.next(includedInTree.size());
        auto itU = includedInTree.find_by_order(r);
        ll u = *itU;
        ll notIncSize = notIncludedInTree.size();
        r=rnd.next(notIncSize);
        auto itV = notIncludedInTree.find_by_order(r);
        ll v = *itV;
        notIncludedInTree.erase(itV);
        includedInTree.insert(v);
        if(rnd.next(2)) swap(u, v);
        edges.push_back({u, v});
    }
    shuffle(edges.begin(), edges.end());
    for (auto& x:edges) {
        cout << x.first << " " << x.second << "\n";
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=atoi(argv[1]);
    int h=rnd.next(1, 1'000'000);
    vector<int> costs(n);
    for(int i=0; i<n; i++) costs[i]=rnd.next(1, 1'000'000);
    cout << n << " " << h << "\n";
    println(costs);
    treeTCgenerator(n);
}
