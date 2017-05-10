/*input
2 1
1 2
3 3
1 2
1 3
3 2
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

int dp[12345], degree[12345];
int r, k;


int main(){
	while(cin >> r >> k){

		memset(degree, 0, sizeof degree);
		memset(dp, 0, sizeof dp);
		int u, v;
		for(int i = 0; i < k; i++){
			cin >> u >> v;
			degree[--u]++;
			degree[--v]++;
		}

		dp[0] = 1;
		for(int i = 0; i < r; i++)
			for(int j = k*2; j >= degree[i]; j--)
				if(dp[j - degree[i]])
					dp[j] = 1;

		puts(dp[k] ? "S" : "N");
	}
	return 0;
}