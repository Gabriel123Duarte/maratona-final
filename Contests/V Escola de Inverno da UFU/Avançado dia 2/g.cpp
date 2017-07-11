/*input
2
18 19
3
40 60 20
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

#define MAXN 110
ll dp[MAXN][MAXN];
ll v[MAXN], pref[MAXN];

ll get(int i, int j){
	return (pref[j]-pref[i-1])%100;
}

ll solve(int i, int j){
	if(i == j)
		return 0;
	if(i == j-1)
		return v[i]*v[j];
	ll &ans = dp[i][j];
	if(ans != -1)
		return ans;
	ans = 1LL<<60;

	for(int k = i; k < j; k++)
		ans = min(ans, get(i,k)*get(k+1,j) + solve(i, k)+solve(k+1, j));
	return ans; 
}

int main(){
	int n;
	while(cin >> n){
		pref[0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> v[i];
			pref[i] = pref[i-1] + v[i];
		}

		memset(dp, -1, sizeof dp);

		cout << solve(1, n) << endl;
	}
	return 0;
}