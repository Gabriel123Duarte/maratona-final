/*input
3
0.0 0.3 0.1
0.3 0.2 0.8
0.7 0.5 0.1
1
1 1 1
3
0.0 0.3 0.1
0.3 0.2 0.8
0.7 0.5 0.1
3
1 1 10
3 1 1
3 1 2
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

int n;
struct M{
	double m[10][10];
};

M operator*(M a, M b){
	M c;
	memset(c.m, 0, sizeof c.m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				c.m[i][j] += a.m[i][k] * b.m[k][j];
	return c;
}

M fexp(M base, int p){
	M ans;
	memset(ans.m, 0, sizeof ans.m);
	for(int i = 0; i < n; i++)
		ans.m[i][i] = 1;

	while(p){
		if(p&1)
			ans = ans * base;
		base = base * base;
		p >>= 1;
	}
	return ans;
}

int main(){
	while(cin >> n){
		M ans;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> ans.m[i][j];

		int q;
		cin >> q;
		while(q--){
			int i, j, k;
			cin >> i >> j >> k;
			i--, j--;
			M cpy = fexp(ans, k);
			cout << fixed << setprecision(6) << cpy.m[j][i] << endl;
		}
	}
	return 0;
}