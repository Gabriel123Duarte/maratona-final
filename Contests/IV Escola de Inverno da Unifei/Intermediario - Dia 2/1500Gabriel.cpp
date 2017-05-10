/*input
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8
0 5 7 14
1 4 8
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

#define MAXN 1000100
ll vet[MAXN], lazy[MAXN], groups[MAXN];

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, c;
		cin >> n >> c;
		memset(vet, 0, sizeof vet);
		memset(lazy, 0, sizeof lazy);
		memset(groups, 0, sizeof groups);

		int root = sqrt(n);

		int type, p, q;
		ll v;
		while(c--){
			cin >> type >> p >> q;
			p--, q--;
			if(!type){
				cin >> v;
				for(int i = p; i <= q; ){
					if(i % root == 0 && i + root - 1 <= q){
						groups[i / root] += (ll)root*v;
						lazy[i / root] += v;
						i += root;
					}
					else{
						if(lazy[i / root]){
							for(int j = root * (i / root); j < root * (i / root + 1); j++)
								vet[j] += lazy[i/root];
							lazy[i/root] = 0;
						}
						vet[i] += v;
						groups[i/root] += v;
						i++;
					}
				}
			}
			else{
				ll ans = 0;
				for(int i = p; i <= q; ){
					if(i%root == 0 && i + root - 1 <= q){
						ans += groups[i/root];
						i += root;
					}
					else{
						if(lazy[i / root]){
							for(int j = root * (i / root); j < root * (i / root + 1); j++)
								vet[j] += lazy[i/root];
							lazy[i/root] = 0;
						}
						ans += vet[i];
						i++;
					}
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}