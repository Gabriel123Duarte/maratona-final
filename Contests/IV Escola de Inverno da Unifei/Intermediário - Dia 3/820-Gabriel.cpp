/*input
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
0
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

#define MAXV 100
#define INF 0x3f3f3f3f

int res[MAXV][MAXV], mf, f, s, t;
vector<int> p;
vector<int> graph[MAXV];

void augment(int v, int minEdge){
	if(v == s){
		f = minEdge;
		return;
	}
	if(p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int main(){
	int n;
	int network = 1;
	while(scanf("%d", &n), n){
		int c;
		scanf("%d %d %d", &s, &t, &c);
		s--, t--;
		
		for(int i = 0; i < n; i++)
			graph[i].clear();

		memset(res, 0, sizeof res);
		int u, v, w;
		while(c--){
			scanf("%d %d %d", &u, &v, &w);
			u--, v--;
			graph[u].pb(v);
			graph[v].pb(u);
			res[u][v] = res[v][u] += w;
		}

		mf = 0;
		while(1){
			f = 0;
			vector<int> dist(MAXV, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(MAXV, -1);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u == t)
					break;
				for(auto v : graph[u]){
					if(res[u][v] > 0 && dist[v] == INF){
						dist[v] = dist[u] + 1;
						q.push(v);
						p[v] = u;
					}
				}					
			}
			augment(t, INF);
			if(f == 0)
				break;
			mf += f;
		}

		printf("Network %d\n", network++);
		printf("The bandwidth is %d.\n\n", mf);
	}
	return 0;
}