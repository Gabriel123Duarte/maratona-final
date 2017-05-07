/*input
4 5
1 2 1
1 3 2
2 4 1
3 4 1
4 1 2
3 2 
1 2 2
1 3 2
3 2 
1 2 2
1 3 1
4 2
1 2 2
3 4 2
0 0
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

vector<int> graph[2010];
vector<int> S, vis, dfs_low, dfs_num;
int numSCC, dfsNumber;

void tarjan(int u){
	dfs_low[u] = dfs_num[u] = dfsNumber++;
	S.pb(u);
	vis[u] = 1;
	for(auto v : graph[u]){
		if(dfs_num[v] == -1)
			tarjan(v);
		if(vis[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if(dfs_low[u] == dfs_num[u]){
		numSCC++;
		while(1){
			int v = S.back(); S.pop_back();
			vis[v] = 0;
			if(u == v)
				break;
		}
	}
}

int main(){
	int n, m;
	while(cin >> n >> m, n+m){
		for(int i = 0; i < n; i++)
			graph[i].clear();

		int u, v, w;
		while(m--){
			cin >> u >> v >> w;
			u--, v--;
			graph[u].pb(v);
			if(w == 2)
				graph[v].pb(u);
		}

		dfs_num.assign(n, -1);
		dfs_low.assign(n, 0);
		vis.assign(n, 0);
		dfsNumber = numSCC = 0;
		for(int i = 0; i < n; i++)
			if(dfs_num[i] == -1)
				tarjan(i);

		cout << (numSCC == 1) << endl;
	}
	return 0;
}²