/*input
10 4
cirominino
10 654
hermanoteu
7 123
zezinho
6 13
baiano
16 11
pimentafilosofal
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

ll n, k;
string s;
ll dp[26][100001];

ll solve(int last, int id){
	if(id == s.size())
		return 0;
	ll &ans = dp[last][id];
	if(ans != -1)
		return ans;
	ans = solve(last, id+1);
	if((s[id]-'a') >= last)
		ans = max(ans, 26-(s[id]-'a') + solve(s[id]-'a', id+1));
	
	return ans;
}

int main(){
	while(cin >> n >> k){
		cin >> s;
		memset(dp, -1, sizeof dp);
		puts(solve(0, 0) >= k ? "Aceita" : "Rejeita");
	}
	return 0;
}