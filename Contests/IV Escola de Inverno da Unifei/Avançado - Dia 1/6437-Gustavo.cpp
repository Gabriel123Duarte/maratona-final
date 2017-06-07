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

#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> vii;

vector<int> tree;

int find(int id){
	if (tree[id] == id)
		return id;

	return tree[id] = find(tree[id]);
}

void merge(int i, int j){
	tree[find(i)] = tree[find(j)];
}

int main(){

	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;

	for (int cc = 1; cc <= t; cc++){

		int n, m, k;
		int x, y, w;

		cin >> n >> m >> k;
		
		int plants[k];
		
		for(int i = 0; i < k; i++){
			cin >> x;

			plants[i] = x - 1;
		}
		
		vii edges;

		while(m--){
			cin >> x >> y >> w;
			x--; y--;

			edges.pb(iii(w, ii(x, y)));
		}

		sort(edges.begin(), edges.end());
		
		tree.clear();
		
		for (int i = 0; i < n; i++)
			tree.pb(i);

		for (int i = 0; i < k - 1; i++)
			merge(plants[i], plants[i + 1]);

		int ans = 0;

		for (int i = 0; i < edges.size(); i++){
			iii aux = edges[i];

			if (find(aux.s.f) != find(aux.s.s)){
				ans += aux.f;
				merge(aux.s.f, aux.s.s);
			}
		}

		printf("Case #%d: %d\n", cc, ans);
	}

	return 0;
}