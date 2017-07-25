/*input
4 1.50
2 1 4 1
6 2.50
300 100 500 100 100 200
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

int n;
double f;
vector<int> v;
int dp[550][550];
int pref[550];

int get(int i, int j){
	return pref[j] - (i ? pref[i-1] : 0);
}

int solve(int i, int j){
	if(i >= j)
		return 0;
	if(i+1 == j)
		return max(v[i],v[j]);
	int &ans = dp[i][j];
	if(ans != -1)
		return ans;
	ans = 1<<30;

	for(int x = i; x <= j; x++)
		ans = min(ans, max(get(i, x), get(x+1, j)) + solve(i, x) + solve(x+1, j));
	return ans;
}

int main(){
	while(cin >> n >> f, n+f){
		int x;
		v.clear();
		for(int i = 0; i < n; i++){
			cin >> x;
			v.pb(x);
		}

		for(int i = 0; i < n; i++)
			v.pb(v[i]);
		for(int i = 0; i < v.size(); i++){
			pref[i] = v[i];
			if(i)
				pref[i] += pref[i-1];

		}
		memset(dp, -1, sizeof dp);
		double ans = 1LL<<60;
		for(int i = 0; i+n <= v.size(); i++)
			ans = min(ans, f*solve(i, i+n-1));
		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}