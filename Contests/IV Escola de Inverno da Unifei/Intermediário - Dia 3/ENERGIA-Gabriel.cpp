/*input
6 7
1 2
2 3
3 4
4 5
5 6
6 2
1 5
4 3
1 2
4 2
1 4
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

int p[110];
int find(int i){
	return p[i] == i ? i : p[i] = find(p[i]);
}
void merge(int i, int j){
	p[find(i)] = p[find(j)];
}

int main(){
	int n, m;
	int teste = 1;
	while(cin >> n >> m, n+m){
		for(int i = 0; i < n; i++)
			p[i] = i;
		int u, v;
		int ans = n;
		while(m--){
			cin >> u >> v;
			if(find(u-1) != find(v-1)){
				merge(u-1, v-1);
				ans--;
			}
		}

		printf("Teste %d\n", teste++);
		puts(ans == 1 ? "normal\n" : "falha\n");
	}
	return 0;
}