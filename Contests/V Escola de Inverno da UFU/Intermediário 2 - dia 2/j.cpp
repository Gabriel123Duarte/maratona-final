/*input
100
3
25 50 75
10
4
4 5 7 8
0
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

int v[100];
int dp[100][100];
int l, n;

int solve(int l, int r){
	if(l+1 == r)
		return 0;
	int &ans = dp[l][r];
	if(ans != -1)
		return ans;
	ans = 1<<30;
	for(int i = l+1; i < r; i++)
		ans = min(ans, solve(l, i) + solve(i, r) + v[r]-v[l]);
	return ans;
}

int main(){
	while(cin >> l, l){
		cin >> n;
		v[0] = 0;
		v[n+1] = l;
		for(int i = 1; i <= n; i++)
			cin >> v[i];
		memset(dp, -1, sizeof dp);
		cout << "The minimum cutting is " << solve(0, n+1) << ".\n";
	}	
	return 0;
}