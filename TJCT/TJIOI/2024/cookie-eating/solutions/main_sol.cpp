#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, m, c;
	cin >> n >> m >> c;
	c%=(n+m);
	if(c<=n&&c>0) cout << "Cookie Monster\n";
	else cout << "Elmo\n";
}
