/*input
5 6 8 5 2 6
2 25 62
3 31 5 6 
5 12 12 52 15 20
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

#define LIM 100010

int n;
int v[110];
int dp[110][201000];

int solve(int id, int diff){
	if(id == n)
		return abs(diff);
	int &ans = dp[id][diff+LIM];
	if(ans != -1)
		return ans;
	return ans = min(solve(id+1, diff+v[id]), solve(id+1, diff-v[id]));
}

int main(){
	int caso = 1;
	while(cin >> n, n){
		printf("Case %d: ", caso++);
		
		for(int i = 0; i < n; i++)
			cin >> v[i];
		
		memset(dp, -1, sizeof dp);
		cout << solve(0, 0) << endl;
	}
	return 0;
}