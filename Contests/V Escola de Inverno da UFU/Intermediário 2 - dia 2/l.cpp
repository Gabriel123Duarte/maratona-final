/*input
3
3
500 5
300 4
30 2
10
680
5
500 5
300 4
100 1
120 1
200 3
12
1120
5
500 5
300 4
100 1
120 1
200 3
12
1020
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

int v[100], w[100];
int dp[110][110];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> v[i] >> w[i];

		int k, r;
		cin >> k >> r;
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= k; j++){
				dp[i][j] = dp[i-1][j];
				if(j >= w[i])
					dp[i][j] = max(dp[i][j], v[i]+dp[i-1][j-w[i]]);
			}

		if(dp[n][k] >= r)
			puts("Missao completada com sucesso");
		else
			puts("Falha na missao");
	}
	return 0;
}