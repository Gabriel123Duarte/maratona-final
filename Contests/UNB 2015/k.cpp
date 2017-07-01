/*input
105
231
7163
89348965057411
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

ll mulmod(ll a, ll b, ll c){
	ll x = 0, y = a%c;
	while(b){
		if(b%2 == 1)
			x = (x+y) % c;
		y = (y*2) %c;
		b /= 2;
	}
	return x%c;
}

ll gcd(ll a, ll b){
	return !b ? a : gcd(b, a%b);
}

ll pollard_rho(ll n){
	int i = 0, k = 2;
	ll x = 3, y = 3;
	while(1){
		i++;
		x = (mulmod(x, x, n) + n - 1) %n;
		ll d = gcd(abs(y-x), n);
		if(d != 1 && d != n)
			return d;
		if(i ==k)
			y = x, k *= 2;
	}
}

bool isPrime(ll x){
	if(x == 1)
		return 0;
	for(ll i = 2; i*i <= x; i++)
		if(x % i == 0)
			return 0;
	return 1;
}

#define MAXN 1000100
bitset<MAXN + 10> bs;
vector<ll> primes;

void pre(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= MAXN; i++){
		if(bs[i]){
			for(ll j = i*i; j <= MAXN; j += i)
				bs[j] = 0;
			primes.pb(i);
		}
	}
}

ll get(ll x){
	for(auto p : primes)
		if(x % p == 0)
			return p;
	return 0;
}

int main(){
	pre();
	ll n;
	while(cin >> n, n){
		ll a = pollard_rho(n);
		if(a > n / a)
			a = n / a;
		//ll c = pollard_rho(n/ans);
		ll b = n/a;
		if(a > b)
			swap(a, b);
		ll c = get(b);
		b = b/c;
		ll v[] = {a, b, c};
		sort(v, v+3);
		printf("%lld = %lld x %lld x %lld\n", n, v[0], v[1], v[2]);
	}
	return 0;
}