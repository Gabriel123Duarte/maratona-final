/*input
2
3
2  3  5
4
1  2  4  6
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

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int v[n];

		int sum = 0;
		for(int i = 0; i < n; i++){
			cin >> v[i];
			sum += v[i];
		}

		int dp[n+1][sum+10];
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= sum; j++){
				dp[i][j] = dp[i-1][j];
				if(j >= v[i-1])
					dp[i][j] = max(dp[i][j], v[i-1]+dp[i-1][j-v[i-1]]);
			}	
		int first = sum-dp[n][sum/2];
		int second = abs(sum-first);
		cout << abs(first-second) << endl;
	}
	return 0;
}