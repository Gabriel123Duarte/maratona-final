#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> ii;

struct edge{
	int u, v, c;
	edge(){}
	edge(int a, int b, int _c){
		u = a;
		v = b;
		c = _c;
	}
};

vector<edge> ed;
vector<int> g[10000];

void addEdge(int u, int v, int f){
	ed.pb(edge(u, v, f)); // w
	g[u].pb(ed.size()-1); 
	ed.pb(edge(v, u, 0)); // -w Para minCost
	g[v].pb(ed.size()-1); 
}

const int N = 1000000;

int dist[N];
int pai[N];
#define INF 0x3f3f3f3f

bool bfs(int s, int t){
	memset(dist, INF, sizeof dist);
	memset(pai, -1, sizeof pai);
	dist[s] = 0;
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto vv : g[u]){
			int v = ed[vv].v;
			int c = ed[vv].c;
			if(dist[v] > dist[u]+1 && c > 0){
				dist[v] = dist[u] + 1;
				q.push(v);
				pai[v] = u;
			}
		}
	}
	return dist[t] != INF;
}

int ptr[N];

int dfs(int u, int t, int maxflow = INF){
	if(u == t)
		return maxflow;
	for(int &i = ptr[u]; i < g[u].size(); i++){
		int id = g[u][i];
		int v = ed[id].v;
		int c = ed[id].c;
		if(dist[v] == dist[u] + 1 && c > 0){
			int gar = dfs(v, t, min(maxflow, c));
			ed[id].c -= gar;
			ed[id^1].c += gar;
			return gar;
		}
	}
	return 0;
}

int dinic(int s, int t){
	int ans = 0;
	while(bfs(s, t)){
		memset(ptr, 0, sizeof ptr);
		int flowAtual;
		while((flowAtual = dfs(s, t)))
			ans += flowAtual;
	}
	return ans;
}

int main(){

	return 0;
}