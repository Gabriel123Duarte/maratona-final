/*input
2
1 1 1
2 0 4
3
1 0 0
0 1 0
0 0 0
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

int v[3][110];
int n;
bool vis[110][110][110];
bool dp[110][110][110];

bool solve(int a, int b, int c){
	if(!a && !b && !c)
		return 1;
	bool &ans = dp[a][b][c];
	if(vis[a][b][c])
		return ans;
	vis[a][b][c] = 1;
	ans = 0;

	if(a && v[0][a] % 3 == 0)
		ans |= solve(a-1, b, c);

	if(b && v[1][b] % 3 == 0)
		ans |= solve(a, b-1, c);

	if(c && v[2][c] % 3 == 0)
		ans |= solve(a, b, c-1);

	if(a && b && (v[0][a] + v[1][b]) % 3 == 0)
		ans |= solve(a-1, b-1, c);

	if(a && c && (v[0][a] + v[2][c]) % 3 == 0)
		ans |= solve(a-1, b, c-1);

	if(b && c && (v[1][b] + v[2][c]) % 3 == 0)
		ans |= solve(a, b-1, c-1);

	if(a && b && c && (v[0][a] + v[1][b] + v[2][c]) % 3 == 0)
		ans |= solve(a-1, b-1, c-1);
	return ans;
}

int main(){
	while(cin >> n, n){
		for(int i = 1; i <= n; i++)
			cin >> v[0][i] >> v[1][i] >> v[2][i];
		memset(vis, 0, sizeof vis);
		cout << solve(n, n, n) << endl;
	}
	return 0;
}