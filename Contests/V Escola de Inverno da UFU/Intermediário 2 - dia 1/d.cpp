/*input
1
3
100
90
200
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

#define LIM 45000
int n;
int v[110];
int dp[101][45000];
int maxi = 0;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", v+i);

		memset(ans, -1, sizeof ans);


	}
	return 0;
}