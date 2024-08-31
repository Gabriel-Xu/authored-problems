#include <bits/stdc++.h>
using namespace std;

const int mn=2e5;
vector<int> adj[mn];
bool visited[mn]={0};
int cost[mn];

int dfs(int node) {
	visited[node]=true;
	long long subtree_sum=0;
	for(int u:adj[node]) {
		if(!visited[u]) {
			subtree_sum+=dfs(u);
		}
	}
	if(subtree_sum==0) return cost[node];
	return min((long long)cost[node], subtree_sum);
}

int main() {
	int n, h; cin >> n >> h;
	for(int i=0; i<n; i++) cin >> cost[i];
	for(int i=0; i<n-1; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << (long long)dfs(0)*h;
}
