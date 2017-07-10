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
#define LOG 20
#define INF 0x3f3f3f3f
vector<int> tree[MAXN];
int parent[MAXN][LOG], height[MAXN], subTree[MAXN], parent2[MAXN];
int color[MAXN];
bool removed[MAXN];

void dfs(int u, int p, int h){
	parent[u][0] = p;
	height[u] = h;

	for(int i = 1; i < LOG; i++)
		if(parent[u][i-1] != -1)
			parent[u][i] = parent[parent[u][i-1]][i-1];

	for(auto v : tree[u])
		if(v != p)
			dfs(v, u, h+1);

}

int getLca(int u, int v){
	if(height[u] > height[v])
		swap(u, v);

	for(int i = LOG-1; i >= 0; i--)
		if(parent[v][i] != -1 && height[parent[v][i]] >= height[u])
			v = parent[v][i];

	if(v == u)
		return v;

	for(int i = LOG-1; i >= 0; i--)
		if(parent[u][i] != parent[v][i]){
			u = parent[u][i];
			v = parent[v][i];
		}

	return parent[u][0];
}

int dist(int u, int v){
	return height[u] + height[v] - 2*height[getLca(u, v)];
}

int totalV;
int dfs1(int u, int p){
	subTree[u] = 1;
	totalV++;
	for(auto v : tree[u])
		if(v != p && !removed[v]){
			dfs1(v, u);
			subTree[u] += subTree[v];
		}
}

int dfs2(int u, int p){
	for(auto v : tree[u])
		if(v != p && !removed[v] && subTree[v] > totalV/2)
			return dfs2(v, u);
	return u;
}

void decompose(int root, int p){
	totalV = 0;
	dfs1(root, root);
	int centroid = dfs2(root, root);
	if(p == -1)
		p = centroid;
	parent2[centroid] = p;
	removed[centroid] = 1;
	for(auto v : tree[centroid])
		if(!removed[v] && v != p)
			decompose(v, centroid);

}

set<ii> nodes[MAXN];

int dist2(int u){
	int ans = 1<<30;
	while(nodes[u].size()){
		auto it = *nodes[u].begin();
		if(color[it.snd]){
			ans = min(ans, it.first);
			break;
		}
		nodes[u].erase(it);

	}
	return ans;
}

int main(){
	//freopen("in.c", "rt", stdin);
	int n;
	cin >> n;
	int u, v;

	for(int i = 1; i < n; i++){
		cin >> u >> v;
		u--, v--;
		tree[u].pb(v);
		tree[v].pb(u);
	}

	memset(parent, -1, sizeof parent);
	memset(color, 0, sizeof color);
	dfs(0, 0, 0);
	decompose(0, -1);


	int q;
	cin >> q;
	while(q--){
		cin >> u >> v;
		v--;
		if(!u){
			color[v] ^= 1;
			if(color[v]){
				int x = v;
				while(1){
					nodes[x].insert({dist(v, x), v});
					if(x == parent2[x])
						break;
					x = parent2[x];
				}
			}
		}
		else{
			int x = v;
			int ans = INF;

			while(1){
				ans = min(ans, dist(x, v) + dist2(x));
				if(x == parent2[x])
					break;
				x = parent2[x];
			}
			if(ans >= INF)
				ans = -1;
			cout << ans << endl;
		}
	}
	return 0;
}
