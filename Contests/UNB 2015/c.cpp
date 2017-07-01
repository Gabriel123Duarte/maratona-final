/*input
3 4
101 95 991
1 4 20
2 3 5
4 3 20
1 2 5
2 2
1 2
1 3 15
2 1 30
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

int n, m, k;
int graph[110][110];
int dp[17][1<<17];
vector<int> pos;

bool isPrime(ll x){
	if(x == 1 || x == 0)
		return 0;
	for(ll i = 2; i*i <= x; i++)
		if(x % i == 0)
			return 0;
	return 1;
}

int solve(int id, int bit){
	if(bit == (1<<k)-1)
		return graph[pos[id]][pos[0]];
	int &ans = dp[id][bit];
	if(ans != -1)
		return ans;
	ans = 0x3f3f3f3f;
	for(int i = 0; i < k; i++)
		if(!(bit&1<<i))
			ans = min(ans, graph[pos[id]][pos[i]] + solve(i, bit|1<<i));

	return ans;
}

int main(){
	while(cin >> n >> m){
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				graph[i][j] = i==j ? 0 : 0x3f3f3f3f;

		int x;
		pos.clear();
		pos.pb(n);
		for(int i = 0; i < n; i++){
			cin >> x;
			if(isPrime(x))
				pos.pb(i);
		}
		k = pos.size();
		int a, b, c;
		while(m--){
			cin >> a >> b >> c;
			a--, b--;
			graph[a][b] = graph[b][a] = min(graph[a][b], c);
		}

		for(int k = 0; k <= n; k++)
			for(int i = 0; i <= n; i++)
				for(int j = 0; j <= n; j++)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

		memset(dp, -1, sizeof dp);
		cout << solve(0, 1) << endl;
	}
	return 0;
}