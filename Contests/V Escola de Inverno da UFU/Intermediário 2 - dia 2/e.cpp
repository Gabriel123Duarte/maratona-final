/*input
5 5 3
2 2 1
3 3 2
2 4 3
1 1
5 5 4
3 2 1
3 5 2
2 5 3
1 5 4
3 3
0 0 0
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

int n, m, k;
int grid[25][25][2010];
int dp[25][25][2010];
int dx[] = {-1, 1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, -1, 1};
int ult;

bool ok(int i, int j){
	return !(i < 0 || i >= n || j < 0 || j >= m);
}

int solve(int i, int j, int k){
	if(k > ult)
		return 0;
	int &ans = dp[i][j][k];
	if(ans != -1)
		return ans;
	ans = grid[i][j][k+1] + solve(i, j, k+1);
	for(int x = 0; x < 8; x++){
		int ni = i+dx[x], nj = j+dy[x];
		if(!ok(ni, nj)) continue;
		ans = max(ans, grid[ni][nj][k+1] + solve(ni, nj, k+1));
	}
	return ans;
}

int main(){
	while(cin >> n >> m >> k, n+m+k){
		ult = 0;
		memset(grid, 0, sizeof grid);
		while(k--){
			int x, y, t;
			cin >> x >> y >> t;
			x--, y--;
			grid[x][y][t]++;
			ult = max(ult, t);
		}

		int x, y;
		cin >> x >> y;
		x--, y--;
		memset(dp, -1, sizeof dp);
		cout << solve(x, y, 0) << endl;
	}
	return 0;
}