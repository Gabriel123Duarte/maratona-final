/*input
3
3 2 1
4
3 4 2 1
6
6 2 4 1 5 3
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

#define MAXN 1000100
ll bit[2][MAXN];

void update(int id, int x, ll val){
	for(; x < MAXN; x+=x&-x)
		bit[id][x] += val;
}

ll get(int id, int x){
	ll ans = 0;
	for(; x; x-=x&-x)
		ans += bit[id][x];
	return ans;
}

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		memset(bit, 0, sizeof bit);
		ll ans = 0;
		int x;
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			ans += get(1, n) - get(1, x);
			ll aux = get(0, n) - get(0, x);
			update(0, x, 1);
			update(1, x, aux);
		}
		printf("%lld\n", ans);
	}
	return 0;
}