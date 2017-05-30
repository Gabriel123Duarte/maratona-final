/*input
5
0 34
4 34
4 22
1 26
2 4
1 1 18
1 2 11
1 5 39
2 5 15
2 3 41
1 1 22
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

#define MAXN 101000
int n;
vector<int> tree[MAXN];
int values[MAXN], vet[2*MAXN];
vector<int> blocks[2*MAXN];
int in[MAXN], out[MAXN];
int cnt;

void dfs(int u){
	in[u] = cnt++;
	for(auto v : tree[u])
		dfs(v);
	out[u] = cnt;
}

int main(){
	scanf("%d", &n);
	int p, x;
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &p, &x);
		tree[p].pb(i);
		values[i] = x;
	}

	cnt = 0;
	dfs(0);
	cnt++;

	int root = sqrt(cnt);
	values[0] = vet[in[0]] = vet[out[0]] = 1<<30;

	for(int i = 0; i <= n; i++){
		vet[in[i]] = values[i];
		blocks[in[i]/root].pb(values[i]);
	}
	
	for(int i = 0; i <= root; i++)
		sort(all(blocks[i]));


	int type, y;
	while(scanf("%d %d %d", &type, &x, &y) == 3){
		if(type == 1){
			x = in[x];
			for(int i = 0; i < blocks[x/root].size(); i++)
				if(blocks[x/root][i] == vet[x]){
					vet[x] = y;
					blocks[x/root][i] = vet[x];
					sort(all(blocks[x/root]));
					break;
				}
		}
		else{
			int ans = 0;
			int l = in[x], r = out[x];
			for(int i = l; i < r; ){
				if(i%root == 0 && i + root < r){
					ans += abs(blocks[i/root].size() - (blocks[i/root].end() - upper_bound(all(blocks[i/root]), y)));
					i += root;
				}
				else{
					ans += vet[i++] <= y;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}