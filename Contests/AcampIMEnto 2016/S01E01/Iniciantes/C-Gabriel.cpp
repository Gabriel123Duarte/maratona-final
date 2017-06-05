/*input
7
2
4 4
3
5 7 8
5
1 2 54 678 6
3
10 11 12
1
12
1
11
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

map<ll, int> is;
vector<ll> fib;

void pre(){
  	is[1] = is[2] = 1;
  	fib.pb(1);
  	fib.pb(2);
  	while(fib[fib.size()-2] + fib.back() <= 2000000000LL){
  		fib.pb(fib[fib.size()-2] + fib.back());
  		is[fib.back()] = 1;
	}
}

int main(){
	int t;
	cin >> t;
	pre();
	for(int tt = 1; tt <= t; tt++){
		int n;
		cin >> n;
		ll ans = 1;
		ll x;

		for(int i = 0; i < n; i++){
			cin >> x;
			if(!is[x]){
				int aux = 0;
				for(int j = fib.size()-1; j >= 0; j--){
					if(fib[j] <= x){
						aux += x/fib[j];
						x %= fib[j];
					}
				}
				ans *= aux;
			}
		}

		printf("Case %d: %lld\n", tt, ans);
	}
	return 0;
}