/*input
2
1 200
5 6 8
2 350
3 3 16
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

double sq(double x){
	return x*x;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		double n, l, b, B, H;
		cin >> n >> l >> b >> B >> H;

		double ans = 0.0;
		double le = 0, ri = H;

		for(int i = 0; i < 10000; i++){
			double mid = (le+ri)/2.0;
			double v = M_PI * mid * (sq(b) + b*(b + (B-b)*mid/H) + sq((b + (B-b)*mid/H))) / 3;
			v *= n;
			if(v <= l){
				ans = mid;
				le = mid;
			}
			else
				ri = mid;
		}

		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}