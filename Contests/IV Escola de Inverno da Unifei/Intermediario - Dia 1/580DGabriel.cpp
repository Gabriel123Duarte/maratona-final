/*input
6 3 6
2 3 4 1 5 6
1 5 3
5 1 4
2 6 1
2 4 3
3 5 3
4 5 6
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

#define MAXN 19

int n, m, k;
ll inc[MAXN][MAXN];
ll satis[MAXN];
ll dp[1<<MAXN][MAXN];

ll solve(int bit, int last){
	if(__builtin_popcount(bit) == m)
		return 0;
	ll &ans = dp[bit][last];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int i = 0; i < n; i++)
		if(!(bit&(1<<i)))
			ans = max(ans, satis[i] + inc[last][i] + solve(bit|(1<<i), i));
	return ans;
}

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> satis[i];

	int x, y;
	ll c;
	while(k--){
		cin >> x >> y >> c;
		inc[x-1][y-1] = c;
	}

	memset(dp, -1, sizeof dp);
	ll ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans, satis[i] + solve(1<<i, i));
	cout << ans << endl;
	return 0;
}