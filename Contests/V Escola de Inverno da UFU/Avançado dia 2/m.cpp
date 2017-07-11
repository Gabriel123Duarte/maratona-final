/*input
1

3
100
90
200
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

#define inf 0x3f3f3f3f
#define MAXN 110

int n;
int v[MAXN];
ll dp[45123];
int total;


int main(){
	int t;
	cin >> t;
	string print;
	while(t--){
		cin >> n;
		total = 0;
		for(int i = 0; i < n; i++){
			cin >> v[i];
			total += v[i];
		}

		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for(int i = 0; i < n; i++)
			for(int j = total/2; j >= v[i]; j--)
				dp[j] |= dp[j-v[i]]<<1LL;

		int ans = total/2;
		if(n&1){
			ll x = 1LL<<(n/2);
			ll y = 1LL<<(n/2+1);
			while(!(dp[ans]&x) && !(dp[ans]&y))
				ans--;
		}
		else
			while(!(dp[ans]&(1LL<<(n/2))))	
				ans--;
		
		cout << print;
		print = "\n";
		printf("%d %d\n", ans, total-ans);
	}
	return 0;
}