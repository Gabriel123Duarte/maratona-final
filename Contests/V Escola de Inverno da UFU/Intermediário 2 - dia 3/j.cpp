/*input
11 7
11 6
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

ll modn;
struct mat{
	ll m[2][2];
};

mat operator

mat fexp(mat base, int p){
	mas ans;
	memset(ans.m, 0, sizeof ans.m);
	for(int i = 0; i < 2; i++)
		ans.m[i][i] = 1;

	while(p){
		if(p&1)
			ans = (ans*base);
		base = base*base;
		p >>= 1;
	}
}

int main(){
	int n, m;
	while(cin >> n >> m){
		modn = 1<<m;

	}
	return 0;
}