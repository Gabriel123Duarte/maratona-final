/*input
1
9
0 1
1 2
2 3
2 4
2 7
7 8
7 6
6 5
5
1 4 10
3 5 3
0 8 5
1 6 10
4 4 100
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

#define MAXN 50100
#define LOG 17

vector<int> tree[MAXN];
int parent[MAXN][LOG], height[MAXN], subTree[MAXN], head[MAXN], chainNode[MAXN], posArray[MAXN], cnt, pos;
ll segTree[4*MAXN];
ll lazy[4*MAXN];

void dfs(int u, int p, int h){
	parent[u][0] = p;
	height[u] = h;
	subTree[u] = 1;

	for(int i = 1; i < LOG; i++)
		if(parent[u][i-1]!=-1)
			parent[u][i] = parent[parent[u][i-1]][i-1];

	for(int i = 0; i < tree[u].size(); i++){
		int v = tree[u][i];
		if(v != p){
			dfs(v, u, h+1);
			subTree[u] += subTree[v];
		}
	}
}

void hld(int u, int p){
	if(head[cnt] == -1)
		head[cnt] = u;
	chainNode[u] = cnt;
	posArray[u] = pos++;

	int id, maxi = -1;
	for(int i = 0; i < tree[u].size(); i++){
		int v = tree[u][i];
		if(v != p && subTree[v] > maxi){
			maxi = subTree[v];
			id = i;
		}
	}

	if(maxi != -1)
		hld(tree[u][id], u);

	for(int i = 0; i < tree[u].size(); i++){
		int v = tree[u][i];
		if(v != p && i != id){
			cnt++;
			hld(v, u);
		}
	}
}

int LCA(int u, int v){
	if(height[u] > height[v])
		swap(u, v);

	for(int i = LOG-1; i >= 0; i--)
		if(parent[v][i] != -1 && height[parent[v][i]] >= height[u])
			v = parent[v][i];

	if(v == u)
		return u;

	for(int i = LOG-1; i >= 0; i--)
		if(parent[v][i] != parent[u][i]){
			u = parent[u][i];
			v = parent[v][i];
		}

	return parent[u][0];
}

void doit(int idx, int l, int r){
	if(lazy[idx]){
		segTree[idx] += (ll)(r-l+1)*lazy[idx];
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
	segTree[idx] = segTree[idx*2] + segTree[idx*2+1];
}

ll get(int idx, int l, int r, int x){
	doit(idx, l, r);
	if(l > x || r < x)
		return 0;
	if(l == r && r == x)
		return segTree[idx];
	return get(idx*2, l, (l+r)/2, x) + get(idx*2+1, (l+r)/2+1, r, x);
}

void updateHld(int u, int v, ll w){
	int uChain = chainNode[u], vChain = chainNode[v];

	while(1){
		uChain = chainNode[u];
		if(uChain == vChain){
			update(1, 0, pos-1, posArray[v], posArray[u], w);
			break;
		}
		update(1, 0, pos-1, posArray[head[uChain]], posArray[u], w);
		u = head[uChain];
		u = parent[u][0];
	}
}

void updateAux(int u, int v, ll w){
	int lca = LCA(u, v);

	if(lca != v && lca != u){
		updateHld(u, lca, w);
		updateHld(v, lca, w);
		update(1, 0, pos-1, posArray[lca], posArray[lca], -w);
	}
	else if(lca == v)
		//printf("Esse caso %d %d %d\n", u, v, lca);
		updateHld(u, lca, w);
	//}
	else
		updateHld(v, lca, w);

}

int main(){
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){	
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			tree[i].clear();
			head[i] = -1;
			for(int j = 0; j < LOG; j++)
				parent[i][j] = -1;
		}

		int u, v;
		for(int i = 1; i < n; i++){
			cin >> u >> v;
			tree[u].pb(v);
			tree[v].pb(u);
		}	

		cnt = pos = 0;
		dfs(0, 0, 0);
		hld(0, 0);
		memset(lazy, 0, sizeof lazy);
		memset(segTree, 0, sizeof segTree);	

		int q;
		cin >> q;
		int x, y;
		ll w;

		while(q--){
			cin >> x >> y >> w;
			updateAux(x, y, w);
		}

		printf("Case #%d:\n", tt);
		for(int i = 0; i < n; i++)
			cout << get(1, 0, pos-1, posArray[i]) << endl;
	}
	return 0;
}