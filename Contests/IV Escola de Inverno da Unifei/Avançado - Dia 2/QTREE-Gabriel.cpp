/*input
1

3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
DONE

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

#define MAXN 10100
#define LOG 15

struct edge{
	int v, w, id;
	edge(int a, int b, int c){
		v = a;
		w = b;
		id = c;
	}
};

vector<edge> tree[MAXN];
int parent[MAXN][LOG], height[MAXN], subTree[MAXN];
int head[MAXN], chainNode[MAXN], chainSize[MAXN], chainPos[MAXN], chains;
int edgePlace[MAXN];
int posArray[MAXN], arr[MAXN], elements, segTree[6*MAXN];

void dfs(int u, int p, int h){
	parent[u][0] = p;
	height[u] = h;
	subTree[u] = 1;

	for(int i = 1; i < LOG; i++)
		if(parent[u][i-1]!=-1)
			parent[u][i] = parent[parent[u][i-1]][i-1];

	for(int i = 0; i < tree[u].size(); i++){
		edge e = tree[u][i];
		if(e.v != p){
			edgePlace[e.id] = e.v;
			dfs(e.v, u, h+1);
			subTree[u] += subTree[e.v];
		}
	}
}

int getLca(int u, int v){
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

int hld(int u, int cost, int p){
	if(head[chains] == -1)
		head[chains] = u;
	chainNode[u] = chains;
	chainPos[u] = chainSize[chains];
	chainSize[chains]++;
	posArray[u] = elements;
	arr[elements++] = cost;

	int id, maxi = -1;
	for(int i = 0; i < tree[u].size(); i++){
		int v = tree[u][i].v;
		if(subTree[v] > maxi && v != p){
			maxi = subTree[v];
			id = i;
		}
	}

	if(maxi >= 0)
		hld(tree[u][id].v, tree[u][id].w, u);

	for(int i = 0; i < tree[u].size(); i++){
		edge e = tree[u][i];
		if(e.v != p && e.v != tree[u][id].v){
			chains++;
			hld(e.v, e.w, u);
		}
	}
}

void build(int idx, int l, int r){
	if(l == r){
		segTree[idx] = arr[l];
		return;
	}
	build(idx*2, l, (l+r)/2);
	build(idx*2+1, (l+r)/2+1, r);
	segTree[idx] = max(segTree[idx*2], segTree[idx*2+1]);
}

void update(int idx, int l, int r, int x, int v){
	if(l > x || r < x)
		return;
	if(l == r && r == x){
		segTree[idx] = v;
		return;
	}

	update(idx*2, l, (l+r)/2, x, v);
	update(idx*2+1, (l+r)/2+1, r, x, v);
	segTree[idx] = max(segTree[idx*2], segTree[idx*2+1]);
}

int query(int idx, int l, int r, int i, int j){
	if(l > j || r < i)
		return 0;
	if(l >= i && r <= j)
		return segTree[idx];
	return max(query(idx*2, l, (l+r)/2, i, j), query(idx*2+1, (l+r)/2+1, r, i, j));
}

int queryMaxi(int u, int v){
	int ans = 0;
	int uChain = chainNode[u];
	int vChain = chainNode[v];

	if(u == v)
		return 0;

	while(1){
		uChain = chainNode[u];
		if(uChain == vChain){
			if(u == v)
				break;
			ans = max(ans, query(1, 0, elements-1, posArray[v]+1, posArray[u]));
			break;
		}
		ans = max(ans, query(1, 0, elements-1, posArray[head[uChain]], posArray[u]));
		u = head[uChain];
		u = parent[u][0];
	}

	return ans;
}

int queryAux(int u, int v){
	int lca = getLca(u, v);
	return max(queryMaxi(u, lca), queryMaxi(v, lca));
}

void updateEdge(int e, int val){
	update(1, 0, elements-1, posArray[edgePlace[e]], val);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			tree[i].clear();
			head[i] = -1;
			chainSize[i] = 0;
			arr[i] = 0;
			for(int j = 0; j < LOG; j++)
				parent[i][j] = -1;
		}

		int u, v, w;
		for(int i = 1; i < n; i++){
			scanf("%d %d %d", &u, &v, &w);
			u--, v--;
			tree[u].pb(edge(v, w, i));
			tree[v].pb(edge(u, w, i));
		}

		chains = elements = 0;
		dfs(0, 0, 0);
		hld(0, 0, 0);
		memset(segTree, 0, sizeof segTree);
		build(1, 0, elements-1);

		char s[110];
		int x, y;
		while(scanf("%s", s), s[0] != 'D'){
			scanf("%d %d", &x, &y);

			if(s[0] == 'Q')
				printf("%d\n", queryAux(x-1, y-1));
			else
				updateEdge(x, y);
			
		}
	}
	return 0;
}