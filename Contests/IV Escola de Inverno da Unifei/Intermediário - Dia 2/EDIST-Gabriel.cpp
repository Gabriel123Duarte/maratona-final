/*input
1
FOOD
MONEY
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

int dp[2010][2010];

int main(){
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;

		for(int i = 0; i < a.size(); i++)
			dp[i][0] = i;
		for(int i = 0; i < b.size(); i++)
			dp[0][i] = i;

		for(int i = 1; i <= a.size(); i++){
			for(int j = 1; j <= b.size(); j++){
				if(a[i-1] == b[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
			}
		}

		cout << dp[a.size()][b.size()] << endl;
	}
	return 0;
}