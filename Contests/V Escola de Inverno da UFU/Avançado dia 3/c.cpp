/*input
1
3 10 2
3 1 4 10
6 3 5 7 8 9 9
5 3 4 5 6 9
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

int t, h, f;
int val[2010][2010];
int dp[2010];

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		cin >> t >> h >> f;
		int x, y;
		memset(val, 0, sizeof val);
		memset(dp, 0, sizeof dp);
		for(int i = 0; i < t; i++){
			cin >> x;
			while(x--){
				cin >> y;
				val[i][y]++;
			}
		}

		for(int i = 0; i < t; i++)
			dp[h] = max(dp[h], val[i][h]);

		for(int i = h - 1; i >= 0; i--){
			for(int j = 0; j < t; j++){
				val[j][i] += max(val[j][i+1], (i + f <= h ? dp[i+f] : 0));
				dp[i] = max(dp[i], val[j][i]);
			}
		}

		cout << dp[0] << endl;
	}
	return 0;
}