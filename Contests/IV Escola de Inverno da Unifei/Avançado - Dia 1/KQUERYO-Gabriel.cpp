/*input
6
8 9 3 5 1 9
5
2 3 5
3 3 7
0 0 11
0 0 2
3 7 4
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

int main(){
	int n;
	cin >> n;
	int v[n+1];
	int root = sqrt(n+1);
	vector<int> blocks[n+1];
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		blocks[i/root].pb(v[i]);
	}

	for(int i = 0; i <= n; i++)
		sort(all(blocks[i]));

	int last_ans = 0;
	int a, b, c;
	int q;
	cin >> q;

	while(q--){
		cin >> a >> b >> c;
		a ^= last_ans;
		b ^= last_ans;
		c ^= last_ans;


		int ans = 0;
		if(a < 1)
			a = 1;
		if(b > n)
			b = n;


		for(int i = a; i <= b; ){
			if(i%root == 0 && i + root < b){
				auto it = upper_bound(all(blocks[i/root]), c);
				ans += (blocks[i/root].end() - it);
				i += root;
			}
			else
				ans += v[i++] > c;
		}

		cout << ans << endl;
		last_ans = ans;
	}
	return 0;
}