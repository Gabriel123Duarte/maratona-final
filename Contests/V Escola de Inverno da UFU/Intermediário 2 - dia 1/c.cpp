/*input
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8
0 5 7 14
1 4 8
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

#define MAXN 100100
ll tree[4*MAXN], lazy[4*MAXN];
ll v[MAXN];

void doit(int idx, int l, int r){
	if(lazy[idx]){
		tree[idx] += (ll)(r-l+1)*lazy[idx];
		if(l != r){
			lazy[idx*2] += lazy[idx];
			lazy[idx*2+1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
}

void update(int idx, int l, int r, int x, int y, ll v){
	doit(idx, l, r);
	if(l > y || r < x)
		return;
	if(l >= x && r <= y){
		lazy[idx] += v;
		doit(idx, l, r);
		return;
	}
	update(idx*2, l, (l+r)/2, x, y, v);
	update(idx*2+1, (l+r)/2+1, r, x, y, v);
	tree[idx] = tree[idx*2] + tree[idx*2+1];
}

ll get(int idx, int l, int r, int x, int y){
	doit(idx, l, r);
	if(l > y || r < x)
		return 0;
	if(l >= x && r <= y)
		return tree[idx];
	return get(idx*2, l, (l+r)/2, x, y) + get(idx*2+1, (l+r)/2+1, r, x, y);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;

		memset(tree, 0, sizeof tree);
		memset(lazy, 0, sizeof lazy);
		int type, x, y, z;
		while(m--){
			cin >> type >> x >> y;
			if(!type){
				cin >> z;
				update(1, 0, n-1, x-1, y-1, z);
			}
			else	
				cout << get(1, 0, n-1, x-1, y-1) << endl;
		}
	}
	return 0;
}