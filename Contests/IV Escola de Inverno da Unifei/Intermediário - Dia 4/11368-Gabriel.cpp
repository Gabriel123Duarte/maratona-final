/*input
4
3
20 30 40 50 30 40
4
20 30 10 10 30 20 40 50
3
10 30 20 20 30 10
4
10 10 20 30 40 50 39 51
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
		vector<ii> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i].fst >> v[i].snd;

		sort(all(v), greater<ii>());
		int w = 1<<30, h = 1<<30;
		int ans = 1;
		
		for(int i = 0; i < n; i++){
			if(!(v[i].fst < w && v[i].snd < h))
				ans++;
			w = v[i].fst;
			h = v[i].snd;
		}

		cout << ans << endl;
	}
	return 0;
}