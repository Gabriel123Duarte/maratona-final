/*input
1
7
2 1
3 2
4 2
4 3
5 3
6 2
10 7
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

#define MAXN 1010
const ll modn = 1e9 + 7;
ll fat[MAXN], inv[MAXN][MAXN], dp[MAXN][MAXN];
int m;

ll fexp(ll base, ll p){
	ll ans = 1;
	while(p){
		if(p&1)
			ans = (ans*base)%modn;
		base = (base*base)%modn;
		p >>= 1;
	}
	return ans%modn;
}

ll comb(int x, int y){
	return (fat[x] * fexp((fat[y] * fat[x-y]) % modn, modn-2))%modn;
}

void pre(int limite){
	fat[0] = fat[1] = 1;
	for(int i = 2; i <= limite; i++)
		fat[i] = (i * fat[i-1])%modn;

	for(int i = 0; i <= limite; i++)
		for(int j = 0; j <= i; j++)
			inv[i][j] = comb(i, j);
}

int main(){

	scanf("%d", &m);
	int t;
	scanf("%d", &t);

	int N[t], P[t];
	int n = 0, p = 0;
	for(int i = 0; i < t; i++){
		scanf("%d %d", N+i, P+i);
		n = max(n, N[i]);
		p = max(p, P[i]);
	}

	pre(n);
	dp[0][0] = 1;
	for(int i = 1; i <= p; i++) // postos
		for(int j = m; j <= n; j++) // policial
			for(int k = m; k <= j; k++)
				dp[i][j] = (dp[i][j] + (inv[j][j-k] * dp[i-1][j-k])%modn)%modn;

	for(int tt = 1; tt <= t; tt++){
		printf("Cenario %d: ", tt);
		printf("%lld\n", dp[P[tt-1]][N[tt-1]]);
	}
	return 0;
}