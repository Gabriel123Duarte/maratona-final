/*input
3
5
7
10
*/

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef unsigned long long ll;
typedef pair<int, int> ii;

const ll modn = 1e9+7;
vector<ll> primes;

void sieve(int n){
	vector<bool> prime(n+1, 1);

	for(int p = 2; p*p <= n; p++){
		if(prime[p]){
			for(int i = p*2; i<=n; i+=p)
				prime[i] = false;
		}
	}

	primes.clear();
	for(int p = 2; p <= n; p++)
		if(prime[p])
			primes.pb(p);
}

ll solve(ll n){
	sieve(n);

	ll ans = 1;

	for(int i = 0; i < primes.size(); i++){
		ll p = primes[i];

		ll exp = 0;
		while(p <= n){
			exp = exp + (n/p);
			p = p*primes[i];
		}

		ans = (ans * (exp/2 + 1))%modn;
	}

	return ans;
}

int main(){
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		printf("Caso %d: ", tt);
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}