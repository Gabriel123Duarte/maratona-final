/*input
6 3 10 18 5
1 2 4 2 5 2 0 1 2 1 2 3 2 4 3 1 3 10 2 3 6 0 3 2 3 4 2 4 5 1 3 5 2 0 5 5
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

#define MAXN 17
#define INF 0x3f3f3f3f

int n, p, m, g, t;
int places[MAXN], timePlaces[MAXN];
int dist[MAXN][MAXN];
int distDijsktra[20100];
int dp[1<<MAXN][MAXN][2];

vector<ii> graph[20100];

void dijkstra(int u){
	for(int i = 0; i < n; i++)
		distDijsktra[i] = INF;
	distDijsktra[u] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > q;
	q.push({0, u});
	while(!q.empty()){
		int u = q.top().snd, d = q.top().fst; q.pop();

		if(d > distDijsktra[u])
			continue;
		for(auto v : graph[u]){
			if(distDijsktra[u] + v.snd < distDijsktra[v.fst]){
				distDijsktra[v.fst] = distDijsktra[u] + v.snd;
				q.push({distDijsktra[v.fst], v.fst});
			}
		}
	}
}


int solve(int bit, int id, bool ok){
	if(bit == (1<<p)-1)
		return !ok ? min(dist[id][0], t) : dist[id][0];
	int &ans = dp[bit][id][ok];
	if(ans != -1)
		return ans;

	ans = INF;
	for(int i = 0; i < p; i++)
		if(!(bit&1<<i)){
			ans = min(ans, dist[id][i]+timePlaces[i]+solve(bit|1<<i, i, ok));
			if(!ok)
				ans = min(ans, t+timePlaces[i]+solve(bit|1<<i, i, 1));
		}
	return ans;
}

int main(){
	cin >> n >> p >> m >> g >> t;
	p++;
	places[0] = timePlaces[0] = 0;
	for(int i = 1; i < p; i++)
		cin >> places[i] >> timePlaces[i];

	int u, v, w;
	while(m--){
		cin >> u >> v >> w;
		graph[u].pb({v, w});
		graph[v].pb({u, w});
	}

	for(int i = 0; i < p; i++){
		dijkstra(places[i]);
		for(int j = 0; j < p; j++)
			dist[i][j] = distDijsktra[places[j]];
	}

	

	memset(dp, -1, sizeof dp);
	if(solve(1, 0, 1) <= g)
		puts("possible without taxi");
	else if(solve(1, 0, 0) <= g)
		puts("possible with taxi");
	else
		puts("impossible");
	return 0;
}