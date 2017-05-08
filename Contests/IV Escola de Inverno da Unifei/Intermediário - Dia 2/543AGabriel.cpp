/*input
3 3 3 100
1 1 1
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

int n, m, b, mod;
int a[550];
ll dp[2][550][550];

/*ll solve(int id, int lines, int bugs){
	if(lines == m)
		return 1;
	if(id == n)
		return 0;
	ll &ans = dp[id&1][lines][bugs];
	if(ans != -1)
		return ans;
	
	ans = solve(id+1, lines, bugs)%mod;
	if(bugs + a[id] <= b)
		ans = (ans + (solve(id, lines+1, bugs+a[id])%mod))%mod;

	return ans;
}
*/

int main(){
	scanf("%d %d %d %d", &n, &m, &b, &mod);
	for(int i = 0; i < n; i++)
		scanf("%d", a+i);

	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){ // Lines
			for(int k = 0; k <= b; k++){ // Bugs
				dp[i&1][j][k] = dp[~i&1][j][k];
				if(j > 0 && k >= a[i-1]){
					dp[i&1][j][k] = ((dp[i&1][j][k]%mod) + (dp[i&1][j-1][k-a[i-1]]%mod))%mod;
				}				
			}
		}
	}	

	ll ans = 0;
	for(int i = 0; i <= b; i++)
		ans = ((ans%mod) + (dp[n&1][m][i]%mod))%mod;

	printf("%lld\n", ans);
	return 0;
}