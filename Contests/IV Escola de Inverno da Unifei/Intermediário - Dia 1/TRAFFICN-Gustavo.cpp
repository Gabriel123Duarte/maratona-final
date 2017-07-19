/*input
1
4 5 3 1 4
1 2 13
2 3 19
3 1 25
3 4 17
4 1 18
1 3 23
2 3 5
2 4 25	
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

vector<viii> graph;
int N, M, K, S, F;

int dijkstra(){
	int dist[N][2];

	for (int i = 0; i < N; i++)
		dist[i][0] = dist[i][1] = 1<<30;

	dist[S][0] = 0;

	priority_queue<iii, vector<iii>, greater<iii> q;

	q.push({0, {S, 0}});

	while(!q.empty()){
		iii aux = q.front(); q.pop();

				
	}

	return min(dist[F][0], dist[F][1]);
}

int main(){

	ios::sync_with_stdio(false);
	int t, x, y, w;

	cin >> t;

	while(t--){
		cin >> N >> M >> K >> S >> F;
		S--; F--;

		graph.assign(N, viii());

		for (int i = 0; i < M; i++){
			cin >> x >> y >> w;
			x--; y--;

			graph[x].push_back(iii(y, ii(w, 0)));
		}

		for (int i = 0; i < K; i++){
			cin >> x >> y >> w;
			x--; y--;

			graph[x].push_back(iii(y, ii(w, 1)));
			graph[y].push_back(iii(x, ii(w, 1)));
		}

		cout << dijkstra() << endl;
	}

	return 0;
}