/*input
4 5
3 1 2 1
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
	int n, t;
	cin >> n >> t;
	vector<int> v(n+1);
	ll prefix[n+1];
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		prefix[i] = v[i] + prefix[i-1];
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		int l = i, r = n;
		while(l <= r){
			int mid = (l+r)/2;
			ll aux = prefix[mid] - prefix[i-1];
			if(aux <= t){
				ans = max(ans, mid-i+1);
				l = mid+1;
			}
			else
				r = mid-1;
		}
	}
	cout << ans << endl;
	return 0;
}