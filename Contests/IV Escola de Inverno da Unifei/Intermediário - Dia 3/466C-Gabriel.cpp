/*input
5
1 2 3 0 3
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
	int n;
	cin >> n;

	int v[n];
	ll sum = 0;
	for(auto &x : v){
		cin >> x;
		sum += x;
	}

	if(sum % 3)
		return 0 * puts("0");

	ll ans = 0;
	ll val = sum / 3, aux = 0;
	int cont = 0;
	for(int i = 0; i < n-1; i++){
		aux += v[i];
		if(aux == 2 * val)
			ans += cont;
		if(aux == val)
			cont++;
	}

	cout << ans << endl;
	return 0;
}