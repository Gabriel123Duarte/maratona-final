/*input
6
1 0 0.50
1 1 0.50
2 0 0.50
2 1 0.50
2 2 0.50
5 3 0.35
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

int n, h;
double p;
double dp[25][8000];

int main(){
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		printf("Caso %d: ", tt);
		cin >> n >> h >> p;	
		
		memset(dp, 0, sizeof dp);
		for(int i = 0; i <= h; i++)
			dp[0][i] = 1;

		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= h; j++){
				dp[i][j] = p*dp[i-1][j];
				if(j)
					dp[i][j] = max(dp[i][j], dp[i][j] + (1-p)*dp[i][j-1]);
			}

		cout << fixed << setprecision(15) << dp[n][h] << endl;
	}
	return 0;
}