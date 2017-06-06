/*input
4
7 4
0 1 1 2 2 2 3
Q 5 7
C 2
Q 5 7
Q 4 6
4 4
2 0 2 3
C 3
Q 1 2
C 1
Q 1 2
3 5
0 3 0
C 1
Q 1 2
C 3
C 1
Q 2 3
1 1
0
Q 1 1
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

int p[20100];
int find(int i){
	return p[i] == i ? i : find(p[i]);
}

int main(){
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		printf("Case #%d:\n", tt);

		int n, k, x;
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> x;
			if(x == 0)
				x = i;
			else
				x--;
			p[i] = x;
		}

		char type;
		int u, v;
		while(k--){
			cin >> type >> u;
			if(type == 'Q'){
				cin >> v;
				puts(find(u-1) == find(v-1) ? "YES" : "NO");
			}
			else{
				u--;
				p[u] = u;
			}
		}
	}
	return 0;
}