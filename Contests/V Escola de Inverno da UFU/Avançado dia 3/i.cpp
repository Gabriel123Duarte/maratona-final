/*input
3
abba 0
mate 1
zabcddcbxy 1
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

int n, k;
char str[1010];
int dp[1010][1010];


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s %d", str, &k);
		n = strlen(str);

		memset(dp, 0, sizeof dp);

		int ans = 0;
		for(int i = n; i >= 1; i--)
			for(int j = i; j <= n; j++){
				dp[i][j] = dp[i+1][j-1];
				dp[i][j] += str[i-1] != str[j-1];
			}

		for(int i = 1; i <= n; i++)
			for(int j = i; j <= n; j++)
				if(dp[i][j] <= k)
					ans = max(ans, j-i+1);
		/*
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++)
				printf("%d - %d = %d\n", i, j, dp[i][j]);
		}
		*/
		printf("%d\n", ans);
	}
	return 0;
}

		