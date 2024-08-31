#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, m, c;
	cin >> n >> m >> c;
	if(c%(n+m)<=n) cout << "Cookie Monster\n";
	else cout << "Elmo\n";
}
