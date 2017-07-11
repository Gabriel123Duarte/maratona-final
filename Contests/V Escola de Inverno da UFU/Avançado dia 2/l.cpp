/*input
5
1
1 1
2
1 1
1 2
2
2 1
1 1
3
1 1
1 2
2 1
4
1 1
1 2
2 1
2 2
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
int bit[MAXN][MAXN];

void update(int x, int y, int val){
	for(int i = x; i < MAXN; i+=i&-i)
		for(int j = y; j < MAXN; j+=j&-j)
			bit[i][j] = max(bit[i][j], val);
}

int get(int x, int y){
	int ans = 0;
	for(int i = x; i; i-=i&-i)
		for(int j = y; j; j-=j&-j)
			ans = max(ans, bit[i][j]);
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		memset(bit, 0, sizeof bit);

		int x[n], y[n];
		int ans = 0;
		for(int i = 0; i < n; i++){
			cin >> x[i] >> y[i];
			int aux = get(x[i], y[i]) + 1;
			ans = max(ans, aux);
			update(x[i], y[i], aux);
		}

		cout << ans << endl;
	}
	return 0;
}