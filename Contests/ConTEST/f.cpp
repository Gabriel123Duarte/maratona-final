/*input
3
0 0 10 10 -20 15
-10 10 5 -5 -8 8
1 89 43 55 43 2
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

		int x[3], y[3];
		for(int i = 0; i < 3; i++)
			cin >> x[i] >> y[i];

		int det = x[0]*y[1] + y[0]*x[2] + x[1]*y[2] - x[2]*y[1] - y[2]*x[0] - x[1]*y[0];
		if(det > 0)
			puts("anti-horario");
		else if(det < 0)
			puts("horario");
		else
			puts("indeterminado");
	}
	return 0;
}