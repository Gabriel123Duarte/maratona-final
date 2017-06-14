/*input
3 3 3 1 2 3 1 2 1 2 3 2 1 3 3
4 5 2 1 4 1 2 2 2 4 1 1 3 1 3 4 2 1 4 2

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

#define INF 0x3f3f3f3f
typedef pair<int, ii> iii;

int n, m, k;
map<ii, int> removed;
map<int, int> mini[10010];
vector<iii> graph[10010];

bool dijkstra(){
	int dist[n][2];
	for(int i = 0; i < n; i++)
		dist[i][0] = dist[i][1] = INF;
	dist[0][0] = 0;
	priority_queue<iii, vector<iii>, greater<iii> > q;
	q.push({0, ii(0, 0)});

	while(!q.empty()){
		int d = q.top().fst, u = q.top().snd.fst, ok = q.top().snd.snd;
		q.pop();

		if(d > dist[u][ok])
			continue;

		for(auto v : graph[u]){
			if(dist[u][ok] + v.snd.fst < dist[v.fst][ok|v.snd.snd]){
				dist[v.fst][ok|v.snd.snd] = dist[u][ok] + v.snd.fst;
				q.push({dist[v.fst][ok|v.snd.snd], ii(v.fst, ok|v.snd.snd)});
			}
		}
	}

	//printf("Valores %d %d\n", dist[n-1][0], dist[n-1][1]);
	return dist[n-1][0] == dist[n-1][1];
}

int main(){
	cin >> n >> m >> k;

	int places[k];
	for(int i = 0; i < k; i++)
		cin >> places[i];

	int u, v, w;
	while(m--){
		cin >> u >> v >> w;
		u--, v--;
		graph[u].pb({v, ii(w, 1)});
		graph[v].pb({u, ii(w, 1)});

		if(mini[u].find(v) == mini[u].end())
			mini[u][v] = mini[v][u] = w;

		mini[u][v] = min(mini[u][v], w);
		mini[v][u] = min(mini[v][u], w);
	}	

	for(int i = 1; i < k; i++){
		removed[{places[i-1]-1, places[i]-1}] = 1;
		removed[{places[i]-1, places[i-1]-1}] = 1;
	}

	map<ii, int> marked;
	for(int i = 0; i < n; i++)
		for(auto &v : graph[i]){
			if(removed[{i,v.fst}] && mini[i][v.fst] == v.snd.fst && !marked[{i,v.fst}]){
				v.snd.snd = 0;	
				marked[{i,v.fst}] = 1;
			}
		}
	/*
	for(int i = 0; i < n; i++){
		printf("NO %d: ", i+1);
		for(auto v : graph[i])
			printf("%d-%d-%d ", v.fst+1, v.snd.fst, v.snd.snd);
		puts("");
	}
	*/


	puts(dijkstra() ? "yes" : "no");
	return 0;
}

	