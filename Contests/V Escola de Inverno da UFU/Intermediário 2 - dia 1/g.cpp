/*input
4 30
12 98
13 25
2 97
19 95
5 20
12 98
3 25
12 97
9 95
11 48
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

int w[1010], val[1010];
int dp[5005][5005];

int main(){
	int n, c;
	int test = 1;
	while(cin >> n >> c, n+c){
		for(int i = 1; i <= n; i++)
			cin >> w[i] >> val[i];

		for(int i = 0; i <= c; i++)
			dp[0][i] = 0;

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= c; j++){
				dp[i][j] = dp[i-1][j];
				if(j >= w[i])
					dp[i][j] = max(dp[i][j], val[i] + dp[i-1][j-w[i]]);
			}

		cout << "Caso " << test++ << ": " << dp[n][c] << endl;
	}
	return 0;
}