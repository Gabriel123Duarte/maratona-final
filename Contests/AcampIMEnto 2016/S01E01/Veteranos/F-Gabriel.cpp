/*input
1
1 2 3 4 5 6
9
1 2 3 4 5 6
10 9 8 7 12 11
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30
31 32 33 34 35 36
37 38 39 40 41 42
43 44 45 46 47 48
49 19 34 27 25 13
0
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
	int n;
	while(cin >> n, n){
		int vet[50];
		memset(vet, 0, sizeof vet);
		int x;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 6; j++){
				cin >> x;
				vet[x]++;
			}
		}

		bool ok = 1;
		for(int i = 1; i < 50; i++)
			ok &= !!vet[i];
		cout << (ok ? "Yes\n" : "No\n");
	}
	return 0;
}