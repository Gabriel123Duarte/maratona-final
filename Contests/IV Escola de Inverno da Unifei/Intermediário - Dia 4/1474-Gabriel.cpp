/*input
25 5 5
5 1000 1000
20 17 31
15 9 2
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

const ll mod = 1000000;

struct M{
	ll m[2][2];
};

M operator*(M a, M b){
	M c;
	memset(c.m, 0, sizeof c.m);

	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			for(int k = 0; k < 2; k++){
				c.m[i][j] += ((a.m[i][k]%mod) * (b.m[k][j]%mod))%mod;
				c.m[i][j] %= mod;
			}
	return c;
}

M fexp(M base, ll p){
	M ans;
	memset(ans.m, 0, sizeof ans.m);
	ans.m[0][0] = ans.m[1][1] = 1;
	while(p){
		if(p&1)
			ans = ans * base;
		base = base * base;
		p>>=1;
	}
	return ans;
}

int main(){
	ll n, k, l;
	while(cin >> n >> k >> l){
		n /= 5;
		if(n < 2){
			printf("%06lld\n", k);
			continue;
		}

		M ans;
		ans.m[0][0] = k;
		ans.m[0][1] = l;
		ans.m[1][0] = 1;
		ans.m[1][1] = 0;
		ans = fexp(ans, n-1);
		ll resp  = ((ans.m[0][0]%mod) * (k%mod) + ans.m[0][1]%mod)%mod;
		printf("%06lld\n", resp);
	}
	return 0;
}