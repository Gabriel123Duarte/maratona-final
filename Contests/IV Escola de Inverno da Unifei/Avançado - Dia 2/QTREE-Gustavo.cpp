/*input
1

3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
DONE
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> vii;

#define f first
#define s second
#define pb push_back
#define N 10100
#define LN 15
#define m ((l + r) / 2)

vector<vii> graph;
int chainNo, chainPai[N], chainInd[N], posInVet[N], posAresta[N];
int subSize[N], parents[N][LN], altura[N];
int tree[N * 4], vet[N], posV;

void build(int id, int l, int r){
	if (l == r){
		tree[id] = vet[l];
		return;
	}

	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, int v){
	if (pos < l or pos > r)
		return;

	if (pos == l && pos == r){
		tree[id] = v;
		return;
	}

	update(id * 2, l, m, pos, v);
	update(id * 2 + 1, m + 1, r, pos, v);
	tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

int get(int id, int l, int r, int i, int j){
	if (i > r or j < l)
		return -1;

	if (l >= i && r <= j)
		return tree[id];

	return max(get(id * 2, l, m, i, j), get(id * 2 + 1, m + 1, r, i, j));			
}

int lca(int u, int v){
	if (altura[u] > altura[v])
		swap(u, v);

	for (int i = LN - 1; i >= 0; i--)
		if (parents[v][i] != -1 && altura[parents[v][i]] >= altura[u])
			v = parents[v][i];

	if (u == v) return u;
	
	for (int i = LN - 1; i >= 0; i--)
		if (parents[u][i] != parents[v][i]){
			u = parents[u][i];
			v = parents[v][i];
		}

	return parents[u][0];	
}

void dfs(int u, int p, int h){

	parents[u][0] = p;
	altura[u] = h;
	subSize[u] = 1;

	for (int i = 1; i < LN; i++)
		if (parents[u][i - 1] != -1)
			parents[u][i] = parents[parents[u][i - 1]][i - 1];

	for (int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i].f;
		int id = graph[u][i].s.s;

		if (v != parents[u][0]){
			posAresta[id] = v;
			dfs(v, u, h + 1);
			subSize[u] += subSize[v];
		}
	}	
}

int query_up(int u, int v){
	if (u == v) return 0;

	int uchain = chainInd[u], vchain = chainInd[v], ans = -1;

	while(1){
		uchain = chainInd[u];

		if (uchain == vchain){
			if (u == v) break;

			ans = max(ans, get(1, 0, posV - 1, posInVet[v], posInVet[u]));
			break;
		}

		ans = max(ans, get(1, 0, posV - 1, posInVet[chainPai[uchain]], posInVet[u]));
		u = chainPai[u];
		u = parents[u][0];
	}

	return ans;
}

void query(int u, int v){

	int lca_uv = lca(u, v);
	int ans = query_up(u, lca_uv);
	int temp = query_up(v, lca_uv);
	printf("%d\n", max(ans, temp));
}

void change(int u, int val){
	update(1, 0, posV - 1, posInVet[posAresta[u]], val);
}

void hld(int curNode, int custo, int pai){
	if (chainPai[chainNo] != -1)
		chainPai[chainNo] = curNode;

	chainInd[curNode] = chainNo;
	posInVet[curNode] = posV;
	vet[posV++] = custo;

	int filhoEsp = -1, ncost;

	for (int i = 0; i < graph[curNode].size(); i++){
		int v = graph[curNode][i].f;
		int c = graph[curNode][i].s.f;

		if (v != parents[curNode][0])
			if (filhoEsp == -1 or subSize[v] >= subSize[filhoEsp]){
				filhoEsp = v;
				ncost = c;
			}
	}

	if (filhoEsp != -1)
		hld(filhoEsp, ncost, curNode);

	for (int i = 0; i < graph[curNode].size(); i++){
		int v = graph[curNode][i].f;
		int c = graph[curNode][i].s.f;

		if (v != parents[curNode][0] && filhoEsp != v){
			chainNo++;
			hld(v, c, curNode);
		}
	}				
}

int main(){

	int t, n, u, v, w;
	char op[15];

	scanf("%d ", &t);

	while(t--){
		scanf("%d", &n);
		graph.assign(n, vii());
		memset(chainPai, -1, sizeof chainPai);
		memset(parents, -1, sizeof parents);
		chainNo = 0;
		posV = 0;

		for (int i = 1; i < n; i++){
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;

			graph[u].pb(iii(v, ii(w, i)));
			graph[v].pb(iii(u, ii(w, i)));
		}

		dfs(0, 0, 0);
		hld(0, -1, -1);
		build(1, 0, posV - 1);

		while(1){
			scanf("%s", op);

			if (op[0] == 'D')
				break;

			scanf("%d %d", &u, &v);

			if (op[0] == 'Q'){
				u--; v--;
				query(u, v);
			}else{
				u--;
				change(u, v);
			}
		}
	}

	return 0;
}