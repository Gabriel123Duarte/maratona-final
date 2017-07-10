/*input
5 5
1 2 1 1 2
1 2
1 3
2 4
2 5
1 2 3
1 1 2
2 1
2 2
2 4
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

#define MAXN 200100
vector<int> tree[MAXN];
int v[MAXN], lvl[MAXN], in[MAXN], out[MAXN], cnt;
vector<int> arr, arr2;

void dfs(int u, int l, int p){
	in[u] = cnt++;
	lvl[u] = l;
	arr.pb(v[u]);

	for(auto v : tree[u])
		if(v != p)
			dfs(v, l^1, u);

	out[u] = cnt++;	
	arr.pb(v[u]);
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> v[i];

	int a, b;
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		a--, b--;
		tree[a].pb(b);
		tree[b].pb(a);
	}

	dfs(0, 0, 0);
	arr2 = arr;
	while(m--){
		int tp, x, val;
		cin >> tp >> x;
		if(tp == 1){
			cin >> val;
			
		}
		else{

		}
	}
	return 0;
}