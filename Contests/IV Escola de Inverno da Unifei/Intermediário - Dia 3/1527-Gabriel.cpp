/*input
5 5
5 3 4 3 2
1 1 2
1 3 4
2 2 4
1 4 5
2 1 3
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

int p[100010], points[100010];

int find(int i){
	return p[i] == i ? i : p[i] = find(p[i]);
}

void merge(int i, int j){
	if(find(i) == find(j))
		return;
	int x = find(i);
	p[find(i)] = p[find(j)];
	points[find(j)] += points[x];
	points[x] = points[find(j)];
}

int main(){
	int n, m;
	while(cin >> n >> m, n+m){
		for(int i = 0; i < n; i++){
			cin >> points[i];
			p[i] = i;
		}

		int ans = 0;
		int q, a, b;
		while(m--){
			cin >> q >> a >> b;
			if(q == 1)
				merge(a-1, b-1);
			else{
				a = find(a-1);
				b = find(b-1);
				if(points[a] > points[b] && find(0) == a)
					ans++;
				if(points[b] > points[a] && find(0) == b)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}