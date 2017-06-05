/*input
1.00
3.71
0.04
5.19
0.00
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
	double v;
	while(cin >> v, v){
		int l = 0, r = 10000;
		int ans = 0;

		while(l <= r){
			int mid = (l+r)/2;
			double tot = 0;
			for(int i = 2; i <= mid+1; i++)
				tot += 1.0/i;

			if(tot >= v){
				ans = mid;
				r = mid-1;
			}
			else
				l = mid+1;
		}

		printf("%d card(s)\n", ans);
	}
	return 0;
}