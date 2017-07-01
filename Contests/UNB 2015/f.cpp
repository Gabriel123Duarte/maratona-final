/*input
5 3 3
4 2
3 5
1 2
1 4
5 1
2 4
3 1 2
3 2
1 2
2 3
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

int p[10010];
int find(int i){
	return p[i] == i ? i : p[i] = find(p[i]);
}
void merge(int i, int j){
	p[find(i)] = p[find(j)];
}

int main(){
	int n, m, q;
	string print;
	while(scanf("%d %d %d", &n, &m, &q) == 3){
		for(int i = 1; i <= n; i++)
			p[i] = i;

		int u, v;
		while(m--){
			scanf("%d %d", &u, &v);
			merge(u, v);
		}

		printf("%s", print.c_str());
		print = "\n";
		while(q--){
			scanf("%d %d", &u, &v);
			puts(find(u) == find(v) ? "S" : "N");
		}
	}
	return 0;
}