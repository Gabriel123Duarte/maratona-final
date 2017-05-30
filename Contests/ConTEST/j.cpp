/*input
3
2
4 2
2 4
4
5 2 3 5
4 2 1 2
5 
5 4 3 1 2
4 3 2 1 5
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

int n;
int a[10], b[10];
int dp[10][1<<10];

int main(){
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		printf("Caso %d: ", tt);
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++)
			cin >> b[i];

		dp[0][0] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < 1<<n; j++){
				dp[i][j] = 1<<30;
				for(int k = 0; k < n; k++){
					if(j&1<<k){
						int v = 0;
						if(a[i-1] > b[k])
							v = 1;
						else if(a[i-1] < b[k])
							v = -1;
						dp[i][j] = min(dp[i][j], v+dp[i-1][j^(1<<k)]);
					}
			}
		}
			
		int ans = dp[n][(1<<n)-1];
		if(ans < 0)
			puts("Maria");
		else if(ans > 0)
			puts("Joao");
		else
			puts("Empate");
	}
	return 0;
}

