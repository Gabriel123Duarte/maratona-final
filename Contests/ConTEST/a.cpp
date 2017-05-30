/*input
3
5 500 2
950 550 750 480 600
4 650 3
600 600 600 600
3 500 3
499 500 501
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

		int n, c, v;
		cin >> n >> c >> v;
		vector<int> vet(n);
		int a = 0;
		for(int i = 0; i < n; i++){
			cin >> vet[i];
			a += vet[i] >= c;
		}
		sort(all(vet));

		printf("%d %d\n", a, vet[max(0, n-v)]);
	}
	return 0;
}