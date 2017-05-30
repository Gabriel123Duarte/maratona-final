/*input
3
1 10 1
11
0
3 10 1
5 5 3
0
3 10 1
5 5 3
2
1 2
2 3
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

int n, b, k;
int vals[110];
vector<int> graph[110];
vector<int> menores;

ii bfs(int bit, int sz){
	vector<int> dist(n, 1<<30);
	vector<int> visited(n, 0);
	queue<int> q;

	for(int i = 0; i < sz; i++)
		if(bit&1<<i){
			q.push(menores[i]);
			dist[menores[i]] = 0;
		}

	while(!q.empty()){
		int u = q.front(); q.pop();
		visited[u] = 1;

		for(auto v : graph[u]){
			if(dist[v] == 1<<30){
				int total = 0;
				for(auto x : graph[v]){
					total += visited[x];				
				}
				if(total >= k){
					dist[v] = 1 + dist[u];
					q.push(v);
				}
			}
		}
	}

	int vis = 0, maxi = 0;
	for(int i = 0; i < n; i++)
		if(dist[i] != 1<<30){
			vis++;
			maxi = max(maxi, dist[i]);
		}

	return {vis, maxi};
}

int main(){
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		printf("Caso %d: ", tt);
		cin >> n >> b >> k;
		for(int i = 0; i < n; i++)
			graph[i].clear();

		menores.clear();
		for(int i = 0; i < n; i++){
			cin >> vals[i];
			if(vals[i] <= b)
				menores.pb(i);
		}

		int l, u, v;
		cin >> l;
		while(l--){
			cin >> u >> v;
			u--, v--;
			graph[u].pb(v);
			graph[v].pb(u);
		}

		int sz = menores.size();
		int total = 0, valor = 0, tempo = 0;

		for(int i = 0; i < 1<<sz; i++){
			int sum = 0;
			for(int j = 0; j < sz; j++)
				if(i&1<<j)
					sum += vals[menores[j]];
				

			if(sum <= b){
				ii ans = bfs(i, sz);
				if(ans.fst > total || (ans.fst == total && sum < valor) || (ans.fst == total && sum == valor && ans.snd < tempo)){
					total = ans.fst;
					valor = sum;
					tempo = ans.snd;
				}
				
			}
		}

		printf("%d %d %d\n", total, valor, tempo);
	}
	return 0;
}