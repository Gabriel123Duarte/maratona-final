/*input
5 3
1 2 3 4 5
3 2
4 78 9
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
	int n, k;
	while(cin >> n >> k){
		ll sum = 0;
		int v[n];
		for(int i = 0; i < n; i++){
			cin >> v[i];
			sum += v[i];
		}

		ll l = *min_element(v, v+n), r = sum;
		ll ans;
		while(l <= r){
			ll mid = (l+r)/2;
			ll last = 0;
			int total = 1;
			for(int i = 0; i < n; i++){
				if(v[i] > mid){
					total = 1<<30;
					break;
				}
				if(v[i] + last <= mid)
					last += v[i];
				else{
					last = v[i];
					total++;
				}				
			}
			if(total <= k){
				ans = mid;
				r = mid-1;
			}
			else
				l = mid+1;
		}

		cout << ans << endl;
	}
	return 0;
}