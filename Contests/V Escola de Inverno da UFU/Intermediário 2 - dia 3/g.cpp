/*input
bcacbcabbaccbab
bccabccbbabacbc
a1b2c3d4e
zz1yy2xx3ww4vv
abcdgh
aedfhr
abcdefghijklmnopqrstuvwxyz
a0b0c0d0e0f0g0h0i0j0k0l0m0n0o0p0q0r0s0t0u0v0w0x0y0z0
abcdefghijklmnzyxwvutsrqpo
opqrstuvwxyzabcdefghijklmn
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

int dp[1010][1010];

int main(){
	string s, t;
	while(getline(cin, s)){
		getline(cin, t);
		memset(dp, 0, sizeof dp);
		int ans = 0;
		for(int i = 1; i <= s.size(); i++)
			for(int j = 1; j <= t.size(); j++){
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				if(s[i-1] == t[j-1])
					dp[i][j] = max(dp[i][j], 1+dp[i-1][j-1]);
				ans = max(ans, dp[i][j]);
			}
		cout << ans << endl;
	}
	return 0;
}