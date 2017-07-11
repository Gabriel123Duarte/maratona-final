/*input
4
2
4 4
3
1 2 3
3
2 4 6
3
1 2 1
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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll x, ans = 0;
		while(n--){
			cin >> x;
			while(x&1)
				x /= 2;
			ans ^= x;
		}

		cout << (ans > 0 ? "YES" : "NO") << endl;
	}
	return 0;
}