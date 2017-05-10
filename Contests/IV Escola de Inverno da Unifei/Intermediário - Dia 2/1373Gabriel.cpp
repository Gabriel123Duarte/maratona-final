/*input
3
lovxxelyxxxxx
xxxxxxxlovely
1
lovxxelyxxxxx
xxxxxxxlovely
3
lovxxxelxyxxxx
xxxlovelyxxxxxxx
4
lovxxxelyxxx
xxxxxxlovely
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

int k;
string a, b;
int dp[1100][1100];

int solve(int i, int j){
	if(i == a.size() || j == b.size())
		return 0;
	int &ans = dp[i][j];
	if(ans != -1)
		return ans;
	ans = 0;
	int ok = 0;
	for(int x = 0; i+x < a.size() && j+x < b.size(); x++){
		if(a[i+x] != b[j+x])
			break;
		ok++;
		if(ok >= k){
			ans = max(ans, ok+solve(i+ok, j+ok));
		}
	}
	
	ans = max({ans, solve(i+1, j), solve(i, j+1)});
	return ans;
}

int main(){
	while(cin >> k, k){
		cin >> a >> b;
		memset(dp, -1, sizeof dp);
		cout << solve(0, 0) << endl;
	}
	return 0;
}	