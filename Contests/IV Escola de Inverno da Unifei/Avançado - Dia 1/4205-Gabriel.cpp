/*input
5 3
10 3
0 0
*/

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<ll, ll> ii;

int n, m;
ii operator+(ii a, ii b){
	a.fst += b.fst;
	a.snd += b.snd;
	return a;
}

ii dp[65][65][65];

ii solve(int id, int used, int clicks){
	if(id == n){
		if(used >= m)
			return clicks < used ? ii(1, 0) : clicks == used ? ii(0, 0) : ii(0, 1);
		return {0, 0};
	}
	ii &ans = dp[id][used][clicks];
	if(ans.fst != -1)
		return ans;
	ans = ii(0, 0);

	if(clicks & 1){
		ans = ans + solve(id+1, used+1, clicks);
		ans = ans + solve(id+1, used, clicks+1);
	}else{
		ans = ans + solve(id+1, used+1, clicks+1);
		ans = ans + solve(id+1, used, clicks);
	}

	return ans;
}

int main(){
	int caso = 1;
	while(cin >> n >> m, n+m){

		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				for(int k = 0; k <= n; k++)
					dp[i][j][k] = ii(-1, -1);
		auto ans = solve(0, 0, 0);
		printf("Case %d: %lld %lld\n", caso++, ans.fst, ans.snd);
	}
	return 0;
}