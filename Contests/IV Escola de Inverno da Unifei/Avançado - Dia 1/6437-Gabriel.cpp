/*input
3
9 14 3
1 8 9
1 2 5
1 3 2
2 3 5
2 4 4
2 5 7
3 5 4
4 5 5
4 6 6
4 7 4
5 7 10
6 7 11
6 8 3
7 8 8
7 9 10
4 5 1
1
1 2 5
1 3 5
1 4 5
2 3 10
3 4 10
10 9 5
1 4 6 9 10
1 2 3
2 3 8
3 4 5
4 5 1
5 6 2
6 7 6
7 8 3
8 9 4
9 10 1
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

int p[220];
int find(int i){
	return p[i] == i ? i : p[i] = find(p[i]);
}
void merge(int i, int j){
	p[find(i)] = p[find(j)];
}

int main(){
	int t, n, m, k;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		cin >> n >> m >> k;
		for(int i = 0; i < n; i++)
			p[i] = i;

		int power[k];
		int u, v, w;
		for(int i = 0; i < k; i++)
			cin >> power[i];

		for(int i = 1; i < k; i++)
			merge(power[i-1]-1, power[i]-1);
		

		vector<pair<int, ii> > graph;	
		while(m--){
			cin >> u >> v >> w;
			graph.pb({w, {u-1, v-1}});
		}

		sort(all(graph));
		ll ans = 0;
		for(auto g : graph){
			if(find(g.snd.fst) != find(g.snd.snd)){
				ans += g.fst;
				merge(g.snd.fst, g.snd.snd);
			}
		}
		printf("Case #%d: %lld\n", tt, ans);
	}
	return 0;
}