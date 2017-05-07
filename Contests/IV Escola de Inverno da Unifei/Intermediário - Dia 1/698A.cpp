/*input
2
2 2
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
int days[110];
int dp[110][5];

int solve(int id, int last){
	if(id == n)
		return 0;
	int &ans = dp[id][last];
	if(ans != -1)
		return ans;
	ans = 1+solve(id+1, 0);
	if(days[id] == 1 && last != 1)
		ans = min(ans, solve(id+1, 1));
	if(days[id] == 2 && last != 2)
		ans = min(ans, solve(id+1, 2));
	if(days[id] == 3){
		if(last != 2)
			ans = min(ans, solve(id+1, 2));
		if(last != 1)
			ans = min(ans, solve(id+1, 1));
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> days[i];
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0) << endl;
	return 0;
}