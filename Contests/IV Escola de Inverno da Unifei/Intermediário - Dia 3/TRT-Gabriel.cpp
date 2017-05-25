/*input
5
1
3
1
5
2
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

int n;
int v[2010], dp[2020][2020];

int solve(int l, int r, int tot){
	if(l == r)
		return v[l] * tot;
	int &ans = dp[l][r];
	if(ans != -1)
		return ans;
	return ans = max(v[l]*tot + solve(l+1, r, tot+1), v[r]*tot + solve(l, r-1, tot+1));
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];

	memset(dp, -1, sizeof dp);
	cout << solve(0, n - 1, 1) << endl;
	return 0;
}