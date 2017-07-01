/*input
1 1 0 0 0
1 1
2 4 4 2 2
9 2
2 1
1 2 1 0 10
1 3 0 2
1 4 3 1 2 11 1
3 4 1 0 100
4
2
3
2
2 7 8 1 1
49 3
5 2
7 1 0 1
1 2 1 0 50
2 3 0 0
3 4 3 0 10 10 10
4 5 0 0
5 6 0 0
5 2 0 1
2 6 10 0 100 100 100 100 100 100 100 100 100 100
5
6
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
typedef pair<ii, ii> iiii;

int M, V, E, C, L;
int dano[110], mana[110];
int dp[110][110];
int moedas[110];
int alavancas[110];
int invAlavancas[110];
vector<iii> graph[110];

#define INF 0x3f3f3f3f
int solve(int id, int x){
	if(x <= 0)
		return 0;
	if(id == M)
		return INF;
	int &ans = dp[id][x];
	if(ans != -1)
		return ans;
	ans = solve(id+1, x);
	return ans = min(ans, mana[id] + solve(id, x-dano[id]));
}

int dijkstra(){
	int dist[V][1<<L][1<<C];
	for(int i = 0; i < V; i++)
		for(int j = 0; j < 1<<L; j++)
			for(int k = 0; k < 1<<C; k++)
				dist[i][j][k] = INF;

	dist[0][0][0] = 0;
	priority_queue<iiii, vector<iiii>, greater<iiii> > q;
	q.push(iiii(ii(0, 0), ii(0, 0)));

	while(!q.empty()){
		int d = q.top().fst.fst, u = q.top().fst.snd;
		int bit1 = q.top().snd.fst, bit2 = q.top().snd.snd;

		q.pop();
		if(d > dist[u][bit1][bit2])
			continue;

		if(u == V-1 && bit2 == (1<<C)-1)
			break;
		for(auto v : graph[u]){
			int newBit1 = bit1;
			int newBit2 = bit2;
		
			if(v.snd.snd == -1 || (newBit1&(1<<invAlavancas[alavancas[v.snd.snd]]))){
				/*if(alavancas[v.snd.snd])
					printf("Tem ala %d\n", v.snd.snd+1);*/
				if(invAlavancas[v.fst] != -1){
					newBit1 |= 1<<invAlavancas[v.fst];
				}
				if(moedas[v.fst] != -1)
					newBit2 |= 1<<moedas[v.fst];
				if(dist[u][bit1][bit2] + v.snd.fst < dist[v.fst][newBit1][newBit2]){
					dist[v.fst][newBit1][newBit2] = dist[u][bit1][bit2] + v.snd.fst;
					q.push(iiii({dist[v.fst][newBit1][newBit2], v.fst}, {newBit1, newBit2}));
				}
			}
		}
	}

	int ans = INF;
	for(int i = 0; i < 1<<L; i++)
		ans = min(ans, dist[V-1][i][(1<<C)-1]);
	
	return ans;
}

int main(){
	while(scanf("%d %d %d %d %d", &M, &V, &E, &C, &L) != EOF){
		for(int i = 0; i < M; i++)
			scanf("%d %d", &dano[i], &mana[i]);
		for(int i = 0; i < V; i++)
			graph[i].clear();

		memset(dp, -1, sizeof dp);
		int a, b, m, l;
		while(E--){
			scanf("%d %d %d %d", &a, &b, &m, &l);
			a--, b--;

			int w = 0;
			int x;
			for(int i = 0; i < m; i++){
				scanf("%d", &x);
				w += solve(0, x);
			}

			//cout << "W " << w << endl;
			graph[a].pb(iii(b, ii(w, l-1)));	
			graph[b].pb(iii(a, ii(w, l-1)));			
		}	

		memset(moedas, -1, sizeof moedas);
		memset(alavancas, -1, sizeof alavancas);
		memset(invAlavancas, -1, sizeof invAlavancas);
		for(int i = 0; i < C; i++){
			int x;
			scanf("%d", &x);
			moedas[x-1] = i;
		}
		for(int i = 0; i < L; i++){
			scanf("%d", alavancas+i);
			alavancas[i]--;
			invAlavancas[alavancas[i]] = i;
		}

		printf("%d\n", dijkstra());
	}
	return 0;
}