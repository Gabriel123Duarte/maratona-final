/*input
3
3 2
3 4
10 4
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
	int t, a, b;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		cin >> a >> b;
		auto axx = 10;
		printf("Caso %d: %d\n", tt, (int)ceil((double)a/(b-1)));
	}
	return 0;
}