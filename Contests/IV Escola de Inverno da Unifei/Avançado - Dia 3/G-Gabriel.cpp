/*input
4 2 1 3 4
*/

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> ii;

int main(){
	int n;
	cin >> n;
	int v[n];
	for(auto &x : v)
		cin >> x;

	bool ok = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			ok &= v[i] >= v[j];
	puts(ok ? "yes" : "no");
	return 0;
}