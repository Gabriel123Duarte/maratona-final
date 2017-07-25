/*input
1 5
3 10 10 10
3 5 10 20
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

ll dp[300][300];
ll pref[300];
int f[300];
 
ll get(int i, int j){
	if(i > j) return 0;
	return pref[j] - (i ? pref[i-1] : 0);
}
ll solve(int l, int r){
	if(r <= l)
		return 0;

	ll &ans = dp[l][r];
	if(ans != -1)
		return ans;
	ans = 1LL<<60;

	for(int i = l; i <= r; i++)
		ans = min(ans, get(l,i-1)+get(i+1,r)+solve(l, i-1)+solve(i+1, r));
	return ans;
}

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		pref[0] = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", f+i);
			pref[i] = f[i];
			if(i)
				pref[i]+=pref[i-1];
		}
	
		memset(dp, -1, sizeof dp);
		printf("%lld\n", solve(0, n-1)); 	 	
	}
	return 0;
}