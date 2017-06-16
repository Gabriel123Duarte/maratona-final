/*input
6 0 1 2 2 4 5 1 2 0 0 	
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

#define MAXN 1010
int n;
vector<int> graph[2*MAXN];
vector<int> vis, match;

int dfs(int l){
	if(vis[l])
		return 0;
	vis[l] = 1;

	for(auto r : graph[l]){
		if(match[r] == -1 || dfs(match[r])){
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int main(){
	cin >> n;
	int k, x;

	for(int i = 0; i < n; i++){
		cin >> k;
		while(k--){
			cin >> x;
			graph[i].pb(x + n);
		}
	}

	int mcmb = 0;	
	match.assign(2*n, -1);
	for(int i = 0; i < n; i++){
		vis.assign(2*n, 0);
		mcmb += dfs(i);
	}

	printf("%d\n", n-mcmb);
	return 0;
}