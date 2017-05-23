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

#define MAXN 50010
vector<int> tree[MAXN];
int heigth[MAXN];
int parent[MAXN];
int ans[MAXN];

void dfs(int u, int p, int h){
	heigth[u] = h;
	parent[u] = p;
	for(auto v : tree[u])
		if(v != p)
			dfs(v, u, h+1);
}

void solve(int u, int v, int w){
	while(u != v){
		if(heigth[u] > heigth[v]){
			ans[u] += w;
			u = parent[u];
		}
		else{
			ans[v] += w;
			v = parent[v];
		}
	}
	ans[u] += w;
}

int main(){
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
			tree[i].clear();

		int u, v, w;
		for(int i = 1; i < n; i++){
			cin >> u >> v;
			tree[u].pb(v);
			tree[v].pb(u);
		}

		dfs(0, 0, 0);
		memset(ans, 0, sizeof ans);

		int q;
		cin >> q;
		while(q--){
			cin >> u >> v >> w;
			solve(u, v, w);
		}

		printf("Case #%d:\n", tt);
		for(int i = 0; i < n; i++)
			cout << ans[i] << endl;
	}
	return 0;
}