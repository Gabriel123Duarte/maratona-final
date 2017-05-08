/*input
7 9
0 6
0 1 1
0 2 1
0 3 2
0 4 3
1 5 2
2 6 4
3 6 2
4 6 4
5 6 1
4 6
0 2
0 1 1
1 2 1
1 3 1
3 2 1
2 0 3
3 0 2
6 8
0 1
0 1 1
0 2 2
0 3 3
2 5 3
3 4 2
4 1 1
5 1 1
3 0 1
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

int n, m;
int s, d;
int graph[550][550];
int dist[550], vis[550];

int dijkstra(){
	for(int i = 0; i < n; i++)
		dist[i] = 1<<30;
	dist[d] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > q;
	q.push({0, d});

	while(!q.empty()){
		int d = q.top().fst, u = q.top().snd;
		q.pop();
		if(d > dist[u])
			continue;

		for(int i = 0; i < n; i++){
			if(graph[i][u] != -1 && dist[u] + graph[i][u] < dist[i]){
				dist[i] = dist[u] + graph[i][u];
				q.push({dist[i], i});
			}
		}
	}

	return dist[s];
}

void bfs(){
	queue<int> q;
	q.push(s);
	memset(vis, 0, sizeof vis);
	vis[s] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();

		for(int i = 0; i < n; i++){
			if(graph[u][i] != -1 && dist[i] == dist[u] - graph[u][i]){
				graph[u][i] = -1;
				if(!vis[i])
					q.push(i);
				vis[i] = 1;
			}
		}
	}
}

int main(){
	while(cin >> n >> m, n+m){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				graph[i][j] = i == j ? 0 : -1;
			
		cin >> s >> d;
		int u, v, w;
		while(m--){
			cin >> u >> v >> w;
			graph[u][v] = w;
		}

		int ans = dijkstra();
		if(ans >= 1<<30){
			puts("-1");
			continue;
		}

		bfs();
		ans = dijkstra();
		if(ans >= 1<<30){
			puts("-1");
			continue;
		}

		cout << ans << endl;
	}
	return 0;
}