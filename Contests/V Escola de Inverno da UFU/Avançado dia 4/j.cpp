/*input
3 1
2 3
3 3
3 10
9 30
1 1
2 2
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

ll dp[50][50];

ll solve(int n, int m){
	if(dp[n][m] != -1)
		return dp[n][m];
	if((n == 1 && m == 3) || (m == 1 && n == 3) || (!n || !m))
		return dp[n][m] = 1;
	
	if((n<=2 && m<=2) || n < 0 || m < 0)
		return dp[n][m] = 0;

	ll ans = 0;
	if(m > 2)
		ans += solve(n-1, 3)*solve(n, m-3);
	if(n > 2)
		ans += solve(n, m-1)*solve(n-3, 1);

	return dp[n][m] = ans;
}

int main(){
	int n, m;
	memset(dp, -1, sizeof dp);
	while(cin >> n >> m, n+m)
		cout << solve(n, m) << endl;

	return 0;
}