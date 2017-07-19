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

#define f first
#define s second
#define pb push_back
#define INF 0x3f3f3f3f
#define UNVISITED -1

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<int> vii;

vector<vii> graph;
vi dfs_low, dfs_num, visited, s;
int dfs_count;
int scc;

void tarjanSCC(int u){
	dfs_num[u] = dfs_low[u] = dfs_count++;
	s.pb(u);
	visited[u] = 1;

	for (int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i];

		if (dfs_num[v] == UNVISITED)
			tarjanSCC(v);

		if (visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if (dfs_low[u] == dfs_num[u]){
		scc++;

		while(1){
			int v = s.back(); s.pop_back();
			visited[v] = 0;
			if (u == v) break;
		}
	}
}

int main(){
	
	int n, m, u, v, p;
	while(scanf("%d %d", &n, &m), (n or m)){
		graph.assign(n, vii());
		dfs_num.assign(n, UNVISITED);
		dfs_low.assign(n, 0);
		visited.assign(n, 0);
		dfs_count = scc = 0;

		while(m--){
			scanf("%d %d %d", &u, &v, &p);
			u--; v--;
			graph[u].pb(v);
			if (p == 2) graph[v].pb(u);
		}

		for (int i = 0; i < n; i++)
			if (dfs_num[i] == UNVISITED)
				tarjanSCC(i);

		if (scc == 1)
			printf("1\n");
		else
			printf("0\n");		
	}

	return 0;
}