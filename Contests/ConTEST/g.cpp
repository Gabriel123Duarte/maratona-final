/*input
3
3 10.00
5.50 3.10 4.80
4 1.00
0.75 0.99 0.82 0.92
2 2.00
3.00 4.00
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
	for(int tt = 1; tt <= t; tt++){
		printf("Caso %d: ", tt);

		int n, x, y, r;
		scanf("%d %d.%d", &n, &x, &y);
		vector<int> vals(n);

		r = x*100 + y;
		for(int i = 0; i < n; i++){
			scanf("%d.%d", &x, &y);
			vals[i] = x*100 + y;
		}

		sort(all(vals));
		int ans = 0;
		int gastou = 0;
		for(int i = 0; i < n; i++){
			if(vals[i] <= r){
				ans++;
				r -= vals[i];
				gastou += vals[i];
			}
		}

		printf("%d %d.%02d\n", ans, gastou/100, gastou%100);
	}
	return 0;
}