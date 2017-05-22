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

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> graph;

#define pb push_back
#define s second
#define f first

int N, M, C, K;

int dijkstra(){

	int dist[N];

	for(int i = 0; i < N; i++)
		dist[i] = 1<<30;

	dist[K] = 0;

	priority_queue<ii, vector<ii>, greater<ii>> q;

	q.push(ii(0, K));

	while(!q.empty()){
		ii aux = q.top(); q.pop();

		if (aux.f > dist[aux.s])
			continue;

		for (auto v: graph[aux.s])
			if (dist[aux.s] + v.s < dist[v.f]){
				dist[v.f] = dist[aux.s] + v.s;
				q.push(ii(dist[v.f], v.f));
			}
	}

	return dist[C - 1];
}

int main(){

	int u, v, w;

	while(scanf("%d %d %d %d", &N, &M, &C, &K), (N || M || C || K)){

		graph.assign(N, vii());

		for (int i = 0; i < M; i++){
			scanf("%d %d %d", &u, &v, &w);

			if (u < C && v == u + 1 or u >= C)
				graph[u].pb(ii(v, w));

			if (v < C && u == v + 1 or v >= C)	
				graph[v].pb(ii(u, w));
		}

		cout << dijkstra() << endl;
	}

	return 0;
}