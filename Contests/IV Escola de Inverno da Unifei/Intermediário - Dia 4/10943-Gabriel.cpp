/*input
20 2
20 2
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
typedef pair<int, int> ii;

const ll mod = 1e6;
ll dp[110][110];
int n, k;

ll solve(int sum, int k){
	if(k == 1)
		return 1;
	ll &ans = dp[sum][k];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int i = 0; i <= min(sum, n); i++)
		ans = (ans+solve(sum-i, k-1))%mod;
	return ans;
}

int main(){
	while(cin >> n >> k, n+k){
		memset(dp, -1, sizeof dp);
		cout << solve(n, k) << endl;
	}
	return 0;
}