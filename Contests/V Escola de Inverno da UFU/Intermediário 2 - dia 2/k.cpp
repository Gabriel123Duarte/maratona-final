/*input
385599124
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

const ll modn = 1e9+7;

ll fexp(int base, ll p){
	ll ans = 1;
	while(p){
		if(p&1)
			ans = (ans*base)%modn;
		base = (base*base)%modn;
		p >>= 1;
	}
	return ans;
}

ll solve(ll x){
	return ((fexp(2, x) * (1 + fexp(2, x))) / 2) % modn;
}

int main(){
	ll n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}