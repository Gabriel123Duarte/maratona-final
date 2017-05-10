/*input
10 11
B A
Entrada A
B GT
GT H
H *
B *
* C
C I
I D
C D
D Saida
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

int n, m;
vector<int> graph[5000];

int bfs(int s, int d){
	vector<int> dist(n, 1<<30);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front(); q.pop();

		for(auto v : graph[u]){
			if(dist[v] == 1<<30){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	return dist[d];
}	

int main(){
	cin >> n >> m;
	map<string, int> mp;
	int idx = 0;

	string s1, s2;
	while(m--){
		cin >> s1 >> s2;
		if(mp.find(s1) == mp.end())
			mp[s1] = idx++;
		if(mp.find(s2) == mp.end())
			mp[s2] = idx++;

		graph[mp[s1]].pb(mp[s2]);
		graph[mp[s2]].pb(mp[s1]);
	}

	cout << bfs(mp["Entrada"], mp["*"]) + bfs(mp["*"], mp["Saida"]) << endl;
	return 0;
}