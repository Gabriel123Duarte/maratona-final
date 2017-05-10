/*input
6
0 8
1 7
1 9
0 3
4 2
4
2 3
5 2
1 4
0 3
2
0 1
2
1 0
0 1
6
0 1000000000
1 1000000000
2 1000000000
3 1000000000
4 1000000000
1
5 0
0
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

#define MAXN 100010
int n;
vector<ii> graph[MAXN];
int p[MAXN], h[MAXN];
ll dist[MAXN];

void dfs(int u = 0, int _p = 0, int _h = 0, ll d = 0){
	p[u] = _p;
	h[u] = _h;
	dist[u] = d;
	for(auto v : graph[u])
		if(v.fst != _p)
			dfs(v.fst, u, _h+1, d+(ll)v.snd);
}

int lca(int u, int v){
	while(u != v){
		if(h[u] > h[v])
			u = p[u];
		else
			v = p[v];
	}
	return u;
}

int main(){
	while(cin >> n, n){
		for(int i = 0; i < n; i++)
			graph[i].clear();

		int a, l;
		for(int i = 1; i < n; i++){
			cin >> a >> l;
			graph[a].pb({i, l});
			graph[i].pb({a, l});
		}

		dfs();
		int q, u, v;
		cin >> q;
		bool first = 1;
		while(q--){
			cin >> u >> v;
			if(!first)
				cout << " ";
			first = 0;
			cout << dist[u] + dist[v] - 2*dist[lca(u, v)];
		}
		cout << "\n";

	}	
	return 0;
}