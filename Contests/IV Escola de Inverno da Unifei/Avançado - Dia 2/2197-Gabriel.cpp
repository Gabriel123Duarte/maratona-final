/*input
4
4 8 1
0 1 1
1 0 2
2 3 1
3 2 2
0 2 5
2 0 6
1 3 5
3 1 6
4 8 1
0 1 1
1 0 10
2 3 10
3 2 1
0 2 10
2 0 1
1 3 1
3 1 10
4 8 2
0 1 1
1 0 2
2 3 1
3 2 2
0 2 5
2 0 6
1 3 5
3 1 6
3 4 1
0 1 5
1 0 6
0 2 7
2 0 8
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


typedef int FTYPE;
typedef int CTYPE;
typedef pair<FTYPE, CTYPE> pfc; // Flow cost

const int MAXV = 110;
const CTYPE CINF = 1<<30;
const FTYPE FINF = 1<<30;

void operator += (pfc &p1, pfc &p2)
{
	p1.first += p2.first;
	p1.second += p2.second;
}

struct Edge
{
	int to;
	FTYPE cap;
	CTYPE cost;
	Edge(int a, FTYPE cp, CTYPE ct)
	{
		to = a;
		cap = cp;
		cost = ct;
	}
};

vector<int> adj[MAXV];
vector<Edge> edge;
int V; // Vertices

inline void add_edge(int u, int v, FTYPE c, CTYPE cst)
{
	adj[u].push_back(edge.size());
	edge.push_back(Edge(v, c, cst));
	adj[v].push_back(edge.size());
	edge.push_back(Edge(u, 0, -cst));
}

FTYPE flow[MAXV];
CTYPE dist[MAXV], pot[MAXV];
int prv[MAXV], e_ind[MAXV];
bool foi[MAXV];

void bellman_ford(int _s)
{
	for(int a = 0; a < V; a++)
		dist[a] = CINF;
	dist[_s] = 0;
	for(int st = 0; st < V; st++)
	{
		for(int v = 0; v < V; v++)
		{
			for(size_t a = 0; a < adj[v].size(); a++)
			{
				int ind = adj[v][a];
				int nxt = edge[ind].to;
				if(!edge[ind].cap)
					continue;
				dist[nxt] = min(dist[nxt], dist[v] + edge[ind].cost);
			}
		}
	}
}

pfc dijkstra(int _s, int _t)
{
	for(int a = 0; a < V; a++)
	{
		dist[a] = CINF;
		foi[a] = 0;
	}
	dist[_s] = 0;
	flow[_s] = FINF;
	while(1)
	{
		int v;
		CTYPE d = CINF;
		for(int a = 0; a < V; a++)
		{
			if(foi[a] || dist[a] >= d)
				continue;
			d = dist[a];
			v = a;
		}
		if(d == CINF)
			break;
		foi[v] = 1;
		for(size_t a = 0; a < adj[v].size(); a++)
		{
			int ind  = adj[v][a];
			int nxt = edge[ind].to;
			if(!edge[ind].cap || dist[nxt] <= dist[v] + edge[ind].cost + pot[v] - pot[nxt])
				continue;
			dist[nxt] = dist[v] + edge[ind].cost + pot[v] - pot[nxt];
			prv[nxt] = v;
			e_ind[nxt] = ind;
			flow[nxt] = min(flow[v], edge[ind].cap);
		}
	}
	if(dist[_t] == CINF)
		return pfc(FINF, CINF);
	for(int a = 0; a < V; a++)
		pot[a] += dist[a];
	pfc ret(flow[_t], 0);
	for(int cur = _t; cur != _s; cur = prv[cur])
	{
		int ind = e_ind[cur];
		edge[ind].cap -= flow[_t];
		edge[ind^1].cap += flow[_t];
		ret.second += flow[_t] * edge[ind].cost;
	}
	return ret;
}

pfc mcmf(int _s, int _t)
{
	pfc ret(0, 0), got;
	bellman_ford(_s);
	for(int a = 0; a < V; a++)
		pot[a] = dist[a];
	while((got = dijkstra(_s, _t)).first != FINF)
		ret += got;
	return ret;
}

inline void mcmf_clear()
{
	edge.clear();
	for(int a = 0; a < V; a++)
		adj[a].clear();
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;

		V = 2*n + 2;
		mcmf_clear();

		for(int i = 1; i <= n; i++){
			add_edge(0, i, k, 0);
			add_edge(i+n, V-1, k, 0);
		}


		int u, v, w;
		while(m--){
			cin >> u >> v >> w;
			add_edge(u+1, v+n+1, 1, w);
		}

		pfc ans = mcmf(0, V - 1);
		if(ans.fst != k*n)
			cout << -1 << endl;
		else
			cout << ans.snd << endl;
	}
	return 0;
}