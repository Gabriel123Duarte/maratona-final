/*input
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
0 0
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
int p[MAXN];
int find(int i){
	return p[i] == i ? i : p[i] = find(p[i]);
}
void merge(int i, int j){
	p[find(i)] = p[find(j)];
}

int main(){
	int n, m;
	while(cin >> n >> m, n+m){
		vector<pair<int, ii> > graph;
		for(int i = 0; i < n; i++)
			p[i] = i;

		int u, v, w;
		ll sum = 0;
		while(m--){
			cin >> u >> v >> w;
			graph.pb({w, ii(u, v)});
			sum += w;
		}

		sort(all(graph));
		ll ans = 0;
		for(auto g : graph){
			if(find(g.snd.fst) != find(g.snd.snd)){
				merge(g.snd.fst, g.snd.snd);
				ans += g.fst;
			}
		}

		cout << sum - ans << endl;
	}
	return 0;
}