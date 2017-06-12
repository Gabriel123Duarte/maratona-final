/*input
4
10 20 30 40
6
1 2 5
1 3 10
1 4 13
2 3 5
2 4 7
3 4 20
3 1
1 2 3 4
2
50 100
1
1 2 100
1 1
1 2
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

#define MAXV 210
#define INF 1<<30

int res[MAXV][MAXV], mf, f, s, t;
vector<int> p;

void augment(int v, int minEdge){
	if(v == s){
		f = minEdge;
		return;
	}
	else if(p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}
int main(){
	int n;
	while(cin >> n){
		int vet[n];
		for(auto &x : vet)
			cin >> x;
		int m;
		cin >> m;
		int V = n*2+2;
		s = 0;		
		t = V-1;
		memset(res, 0, sizeof res);

		for(int i = 1; i <= n; i++)
			res[i][i+n] = vet[i-1];

		int u, v, w;
		while(m--){
			cin >> u >> v >> w;
			res[u+n][v] = w;
		}


		int b, d, x;
		cin >> b >> d;
		for(int i = 0; i < b; i++){
			cin >> x;
			res[0][x] = 1<<30;
		}
		for(int i = 0; i < d; i++){
			cin >> x;
			res[x+n][t] = 1<<30;
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
				for(int v = 0; v < MAXV; v++)
					if(res[u][v] && dist[v] == INF)
						dist[v] = dist[u] + 1, q.push(v), p[v] = u;
			}

			augment(t, INF);
			if(f == 0)
				break;
			mf += f;
		}

		printf("%d\n", mf);
	}
	return 0;
}