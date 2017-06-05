/*input
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4
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
int dist[2010];
int vis[2010];

bool bfs(int start){
	dist[start] = 0;
	queue<int> q;
	q.push(start);

	while(!q.empty()){
		int u = q.front(); q.pop();
		vis[u] = 1;
		for(auto v : graph[u]){
			if(dist[v] == 1<<30){
				dist[v] = dist[u]^1;
				q.push(v);
			}
			else if(dist[v] == dist[u])
				return 0;
		}
	}

	return 1;
}

int main(){
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		printf("Scenario #%d:\n", tt);
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			graph[i].clear();
			dist[i] = 1<<30;
			vis[i] = 0;
		}

		int u, v;
		while(m--){
			cin >> u >> v;
			u--, v--;
			graph[u].pb(v);
			graph[v].pb(u);
		}

		bool ok = 1;
		for(int i = 0; i < n; i++)
			if(!vis[i])
				ok &= bfs(i);
		if(ok)
			puts("No suspicious bugs found!");
		else
			puts("Suspicious bugs found!");
	}
	return 0;
}