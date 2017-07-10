/*input
8 5
105 2 9 3 8 5 7 7
1 2
1 3
1 4
3 5
3 6
3 7
4 8
2 5 1
2 5 2
2 5 3
2 5 4
7 8 2
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

#define MAXV 300100
#define LOG 20
struct node{
	node *l, *r;
	int sum;
	node(){
		l = r = 0;
		sum = 0;
	}
};

int val[MAXV], mp2[MAXV];
int parent[MAXV][LOG], height[MAXV];
int idx;
int n, m;
vector<int> tree[MAXV];
node* roots[MAXV];
map<int, int> mp;

void build(node *cur, int l, int r){
	if(l == r)
		return;
	cur->l = new node();
	cur->r = new node();
	build(cur->l, l, (l+r)/2);
	build(cur->r, (l+r)/2+1, r);
}

void update(node *last, node *cur, int l, int r, int x){
	if(l > x || r < x)
		return;
	if(l == r && r == x){
		cur->sum = last->sum + 1;
		return;
	}
	int mid = (l+r)/2;
	if(x <= mid){
		cur->r = last->r;
		cur->l = new node();
		update(last->l, cur->l, l, mid, x);
	}
	else{
		cur->l = last->l;
		cur->r = new node();
		update(last->r, cur->r, mid+1, r, x);
	}
	cur->sum = cur->l->sum + cur->r->sum;
}

void dfs(int u, int p, int h, node *last){
	parent[u][0] = p;
	height[u] = h;

	for(int i = 1; i < LOG; i++)
		if(parent[u][i-1] != -1)
			parent[u][i] = parent[parent[u][i-1]][i-1];

	roots[u] = new node();
	update(last, roots[u], 0, idx-1, val[u]);

	for(int i = 0; i < tree[u].size(); i++)
		if(tree[u][i] != p)
			dfs(tree[u][i], u, h+1, roots[u]);
}

int getLca(int u, int v){
	if(height[u] > height[v])
		swap(u, v);

	if(u == v)
		return u;
	for(int i = LOG-1; i >= 0; i--)
		if(parent[v][i] != -1 && height[parent[v][i]] >= height[u])
			v = parent[v][i];
	if(u == v)
		return u;
	for(int i = LOG-1; i >= 0; i--){
		if(parent[v][i] != parent[u][i]){
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

int get(node *u, node *v, node *lca, node *p, int l, int r, int k, bool ok){
	if(l == r)
		return l;

	int total = u->l->sum + v->l->sum - lca->l->sum;
	if(!ok)
		total -= p->l->sum;

	int mid = (l+r)/2;
	if(total >= k)
		return get(u->l, v->l, lca->l, p->l, l, mid, k, ok);
	return get(u->r, v->r, lca->r, p->r, mid+1, r, k-total, ok);
}

int main(){
	//freopen("in.c", "rt", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", val+i);
		mp[val[i]] = 1;
	}

	idx = 1;
	for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		mp[it->fst] = idx++;

	for(int i = 0; i < n; i++){
		mp2[mp[val[i]]] = val[i];
		val[i] = mp[val[i]];
	}

	int u, v;
	for(int i = 1; i < n; i++){
		scanf("%d %d", &u, &v);
		u--, v--;
		tree[u].pb(v);
		tree[v].pb(u);
	}

	node *root = new node();
	build(root, 0, idx-1);
	memset(parent, -1, sizeof parent);
	dfs(0, 0, 0, root);

	int k;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &u, &v, &k);
		u--, v--;
		int lca = getLca(u, v);
		printf("%d\n", mp2[get(roots[u], roots[v], roots[lca], roots[parent[lca][0]], 0, idx-1, k, !lca)]);
	}
	return 0;
}