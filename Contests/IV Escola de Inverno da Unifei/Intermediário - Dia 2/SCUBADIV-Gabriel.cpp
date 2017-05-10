/*input
1
5 60
5
3 36 120
10 25 129
5 50 250
1 45 130
4 20 119
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

int n;
int oxi[1234], nitr[1234], weight[1234];
int dp[1234][40][110];

int solve(int id, int x, int y){
	if(!x && !y)
		return 0;
	if(id == n)
		return 1<<30;
	int &ans = dp[id][x][y];
	if(ans != -1)
		return ans;
	return ans = min(solve(id+1, x, y), weight[id]+solve(id+1, max(0, x-oxi[id]), max(0, y-nitr[id])));
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int x, y;
		cin >> x >> y;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> oxi[i] >> nitr[i] >> weight[i];

		memset(dp, -1, sizeof dp);
		cout << solve(0, x, y) << endl;
	}
	return 0;
}