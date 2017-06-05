/*input
3 4
1 1 1
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
	int n, s, x;
	cin >> n >> s;
	int sum = 0;
	int bigger = 0;
	while(n--){
		cin >> x;
		sum += x;
		bigger = max(x, bigger);
	}

	puts(sum-bigger <= s ? "YES" : "NO");
	return 0;
}