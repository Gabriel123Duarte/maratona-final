/*input
5 5
1 8 2 1 9
1 7 3 5 2
1 2 10 3 10
8 4 7 9 1
7 1 3 1 6
4 4
10 1 1 10
1 1 1 1
1 1 1 1
10 1 1 10
2 4
9 10 2 7
5 1 1 5
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

int solve(vector<int> &v){
	int n = v.size();
	int dp[n+10];
	dp[0] = v[0];
	for(int i = 1; i < n; i++){
		if(i == 1)
			dp[i] = max(v[i], dp[i-1]);
		else
			dp[i] = max(v[i] + dp[i-2], dp[i-1]);
	}
	return dp[n-1];
}

int main(){
	int n, m;
	while(cin >> n >> m, n+m){
		vector<int> v(m);
		vector<int> v2;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> v[j];
			v2.pb(solve(v));
		}
		cout << solve(v2) << endl;
	}	
	return 0;
}