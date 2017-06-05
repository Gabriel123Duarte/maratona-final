/*input
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

int p[10100];
int find(int i){
	return p[i] == i ? i : p[i] = find(p[i]);
}

void merge(int i, int j){
	p[find(i)] = p[find(j)];
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		p[i] = i;

	int cc = n;
	bool ok = 1;
	int u, v;
	while(m--){
		cin >> u >> v;
		u--, v--;
		if(find(u) == find(v))
			ok = 0;
		else{
			cc--;
			merge(u, v);
		}
	}

	if(cc != 1)
		ok = 0;
	puts(ok? "YES" : "NO");
	return 0;
}