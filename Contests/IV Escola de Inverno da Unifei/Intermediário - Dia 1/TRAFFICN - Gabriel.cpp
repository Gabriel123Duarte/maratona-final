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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#define INF 0x3f3f3f3f
int n, m, k, s, t;
vector<iii> graph[15000];
int dist[15000][2];

int dijkstra(){
	for(int i = 0; i < n; i++)
		dist[i][0] = dist[i][1] = INF;
	
	dist[s][0] = 0;
	priority_queue<iii, vector<iii>, greater<iii>> q;
	q.push({0, {s, 0}});
	while(!q.empty()){
		int d = q.top().fst, u = q.top().snd.fst, ok = q.top().snd.snd;
		q.pop();

		if(d > dist[u][ok] && d > dist[u][ok])
			continue;

		for(auto v : graph[u]){
			if(v.snd.snd && ok)
				continue;
			if(dist[u][ok] + v.snd.fst < dist[v.fst][v.snd.snd|ok]){
				dist[v.fst][v.snd.snd|ok] = dist[u][ok] + v.snd.fst;
				q.push({dist[v.fst][v.snd.snd|ok], {v.fst, v.snd.snd|ok}});
			}
		}
	}
	return min(dist[t][0], dist[t][1]);
}

int main(){	
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
		s--, t--;

		int u, v, w;
		
		for(int i = 0; i < n; i++)
			graph[i].clear();

		while(m--){
			scanf("%d %d %d", &u, &v, &w);
			u--, v--;
			graph[u].pb({v, {w, 0}});
		}

		while(k--){
			scanf("%d %d %d", &u, &v, &w);
			u--, v--;
			graph[u].pb({v, {w, 1}});
			graph[v].pb({u, {w, 1}});
		}

		int ans = dijkstra();
		if(ans >= INF)
			ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}