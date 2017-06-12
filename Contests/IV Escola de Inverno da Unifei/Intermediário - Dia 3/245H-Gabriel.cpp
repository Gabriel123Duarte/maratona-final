/*input
caaaba
5
1 1
1 4
2 3
4 6
4 5
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

int dp[5010][5010];
int prefix[5010][5010];
char s[5010];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	
	for(int i = 0; i < n; i++)
		dp[i][i] = 1;

	for(int sz = 2; sz <= n; sz++)
		for(int i = 0; i+sz <= n; i++){
			int j = i+sz-1;
			if(sz == 2)
				dp[i][j] = s[i] == s[j];
			else
				dp[i][j] = s[i] == s[j] & dp[i+1][j-1];
		}


	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			prefix[i+1][j+1] = prefix[i+1][j] + prefix[i][j+1] + dp[i][j] - prefix[i][j];
				
	int q;
	int l, r;
	scanf("%d", &q);
	while(q--){
		scanf("%d %d\n", &l, &r);
		l--, r--;
		int sz = r - l;
		int a = l, b = 0, c = min(n-1, l+sz), d = r;

		printf("%d\n", prefix[c+1][d+1] - prefix[a][d+1] - prefix[c+1][b] + prefix[a][b]);
	}

	return 0;
}