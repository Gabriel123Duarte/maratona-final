/*input
4 1 1 1 2 0 1 1 
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

int n, total;
vector<int> graph[1010], vis, degree;

void dfs(int u){
	if(vis[u])
		return;
	vis[u] = 1;
	total++;

	for(auto v : graph[u]){
		if(!vis[v]){
			for(auto x : graph[v])
				degree[x]--;
			dfs(v);
			break;
		}
	}
}

int main(){
	cin >> n;
	int k, x;

	degree.assign(n, 0);
	vis.assign(n, 0);	
	for(int i = 0; i < n; i++){
		cin >> k;
		while(k--){
			cin >> x;
			graph[i].pb(x);
			degree[x]++;
		}
	}

	int ans = 0;
	total = 0;
	while(total != n){
		for(int i = 0; i < n; i++)
			if(!degree[i] && !vis[i]){
				//printf("Indo %d\n", i);
				ans++;
				dfs(i);
			}
	}

	printf("%d\n", ans);
	return 0;
}