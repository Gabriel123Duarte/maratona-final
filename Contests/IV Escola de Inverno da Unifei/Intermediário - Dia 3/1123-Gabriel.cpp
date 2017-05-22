/*input
4 6 3 3
0 1 10
1 2 10
0 2 1
3 0 1
3 1 10
3 2 10
6 7 2 5
5 2 1
2 1 10
1 0 1
3 0 2
3 4 2
3 5 3
5 4 2
5 5 2 4
0 1 1
1 2 2
2 3 3
3 4 4
4 0 5
0 0 0 0
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

int graph[300][300];

int main(){
	int n, m, c, k;
	while(cin >> n >> m >> c >> k, n+m+c+k){
		memset(graph, -1, sizeof graph);

		int u, v, p;
		while(m--){
			cin >> u >> v >> p;
			graph[u][v] = graph[v][u] = p;
		}

		for(int i = 0; i < c; i++)
			for(int j = 0; j < n; j++)
				graph[i][j] = j == i+1 ? graph[i][j] : -1;
		
		for(int i = 0; i < n; i++)
			graph[i][i] = 0;

		vector<int> dist(n, 0x3f3f3f3f);
		dist[k] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > q;
		q.push({0, k});
		while(!q.empty()){
			int d = q.top().fst, u = q.top().snd; q.pop();
			if(d > dist[u])
				continue;
			for(int i = 0; i < n; i++){
				if(graph[u][i] != -1 && dist[u] + graph[u][i] < dist[i]){
					dist[i] = graph[u][i] + dist[u];
					q.push({dist[i], i});
				}
			}
		}

		cout << dist[c-1] << endl;	
	}
	return 0;
}