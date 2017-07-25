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

int n, k;
ll dp[110][110];
ll solve(int num, int k){
	if(k==1)
		return 1;
	ll &ans = dp[num][k];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int i = 0; i <= num; i++)
		ans = (ans+solve(num-i, k-1))%1000000;
	return ans;
}

int main(){
	memset(dp, -1, sizeof dp);
	while(cin >> n >> k, n+k)
		cout << solve(n, k) << endl;
	
	return 0;
}