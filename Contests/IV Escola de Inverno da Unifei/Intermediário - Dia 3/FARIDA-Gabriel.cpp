/*input
2
5
1 2 3 4 5
1
10
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
	int tc;
	cin >> tc;
	for(int TC = 1; TC <= tc; TC++){
		int n;
		cin >> n;
		ll v[n], dp[n+1];
		for(int i = 0; i < n; i++)
			cin >> v[i];	
		
		dp[n] = 0;
		dp[n-1] = v[n-1];
		for(int i = n-2; i >= 0; i--)
			dp[i] = max(dp[i+1], v[i]+dp[i+2]);

		printf("Case %d: %lld\n", TC, dp[0]);
	}
	return 0;
}