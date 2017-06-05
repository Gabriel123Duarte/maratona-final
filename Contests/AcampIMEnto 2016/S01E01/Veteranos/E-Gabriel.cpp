/*input
80 20 40 50
80 10 79 12
0 0 0 0
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
	int n, t1, t2, t3;
	while(cin >> n >> t1 >> t2 >> t3, n+t1+t2+t3){
		int ans = 0;

		for(int i = 0; i < n; i++){
			int tot = 0;	
			int px = i;
			tot += 3*n;
			if(t1-px >= 0)
				tot += t1 - px;
			else
				tot += n + t1-px;

			if(t2-t1 >= 0)
				tot += t2-t1;
			else
				tot += n + t2-t1;

			if(t3-t2 >= 0)
				tot += t3-t2;
			else
				tot += n + t3-t2;

			printf("Aqui %d %d\n", tot, i);
			ans = max(ans, tot);
		}
		cout << ans << endl;
	}
	return 0;
}