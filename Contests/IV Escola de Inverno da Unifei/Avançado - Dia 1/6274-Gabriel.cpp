/*input
4 3
1 2
-2 -3
2 4
2 4
1 2
1 -2
-1 2
-1 -2
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
vector<int> dfs_low, dfs_num, S, visited, comps;
int dfsNumCounter, numSCC;

int n, m;
int idx(int i){
	return i > 0 ? i : n - i;
}

void tarjan(int u){
	dfs_num[u] = dfs_low[u] = dfsNumCounter++;
	S.pb(u);
	visited[u] = 1;

	for(auto v : graph[u]){
		if(dfs_num[v] == -1)
			tarjan(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if(dfs_low[u] == dfs_num[u]){
		while(1){
			int v = S.back();
			S.pop_back();
			visited[v] = 0;
			comps[v] = numSCC;
			if(u == v)
			break; 
		}
		numSCC++;
	}
}

int main(){
	while(cin >> n >> m){
		int V = 2*n + 1;
		for(int i = 0; i <= V; i++)
			graph[i].clear();

		int u, v;
		while(m--){
			cin >> u >> v;
			graph[idx(-u)].pb(idx(v));
			graph[idx(-v)].pb(idx(u));
		}

		dfs_num.assign(V, -1);
		dfs_low.assign(V, 0);
		visited.assign(V, 0);
		comps.assign(V, 0);
		S.clear();
		dfsNumCounter = numSCC = 0;
		for(int i = 1; i < V; i++)
			if(dfs_num[i] == -1)
				tarjan(i);

		bool erro = false;
		vector<int> componentsOne;
		for(int i = 1; i <= V; i++)
			if(comps[idx(i)] == comps[idx(1)] || comps[idx(-i)] == comps[idx(1)])
				componentsOne.pb(i);

		for(auto x : componentsOne)
			if(comps[idx(x)] == comps[idx(-x)])
				erro = true;

		/*for(int i = 1; i <= n; i++)
			if(comps[idx(i)] == comps[idx(-i)])
				erro = true;*/
		puts(erro ? "no" : "yes");
	}
	return 0;
}