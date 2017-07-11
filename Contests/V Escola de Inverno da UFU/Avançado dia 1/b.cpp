/*input
5 5
1 2 1 1 2
1 2
1 3
2 4
2 5
1 2 3
1 1 2
2 1
2 2
2 4
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

#define MAXN 200100
vector<int> tree[MAXN];
int v[MAXN], lvl[MAXN], in[MAXN], out[MAXN], cnt;
vector<int> arr;

ll segTree[2][4*MAXN];
ll lazy[2][4*MAXN];

void build(int idx, int l, int r, int ok){
	lazy[ok][idx] = 0;
	if(l == r){
		segTree[ok][idx] = arr[l];
		return;
	}
	build(idx*2, l, (l+r)/2, ok);
	build(idx*2+1, (l+r)/2+1, r, ok);
	segTree[ok][idx] = segTree[ok][idx*2] + segTree[ok][idx*2+1];
}
void doit(int idx, int l, int r, int ok){
	if(lazy[ok][idx]){
		segTree[ok][idx] += (ll)(r-l+1)*lazy[ok][idx];
		if(l != r){
			lazy[ok][idx*2] += lazy[ok][idx];
			lazy[ok][idx*2+1] += lazy[ok][idx];
		}
		lazy[ok][idx] = 0;
	}
}

void update(int idx, int l, int r, int x, int y, ll v, int ok){
	doit(idx, l, r, ok);
	if(l > y || r < x)
		return;
	if(l >= x && r <= y){
		lazy[ok][idx] += v;
		doit(idx, l, r, ok);
		return;
	}
	update(idx*2, l, (l+r)/2, x, y, v, ok);
	update(idx*2+1, (l+r)/2+1, r, x, y, v, ok);
	segTree[ok][idx] = segTree[ok][idx*2] + segTree[ok][idx*2+1];
}

ll get(int idx, int l, int r, int x, int y, int ok){
	doit(idx, l, r, ok);
	if(l > y || r < x)
		return 0;
	if(l >= x && r <= y)
		return segTree[ok][idx];
	return get(idx*2, l, (l+r)/2, x, y, ok) + get(idx*2+1, (l+r)/2+1, r, x, y, ok);
}

void dfs(int u, int l, int p){
	in[u] = cnt++;
	lvl[u] = l;
	arr.pb(v[u]);

	for(auto v : tree[u])
		if(v != p)
			dfs(v, l^1, u);

	out[u] = cnt-1;	
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	int a, b;
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		a--, b--;
		tree[a].pb(b);
		tree[b].pb(a);
	}

	dfs(0, 0, 0);
	build(1, 0, n-1, 0);
	build(1, 0, n-1, 1);

	while(m--){
		int tp, x, val;
		scanf("%d %d", &tp, &x);
		x--;
		if(tp == 1){
			scanf("%d", &val);
			update(1, 0, n-1, in[x], out[x], val, lvl[x]);
			update(1, 0, n-1, in[x], out[x], -val, lvl[x]^1);
		}
		else
			printf("%lld\n", get(1, 0, n-1, in[x], in[x], lvl[x]));
	}
	return 0;
}