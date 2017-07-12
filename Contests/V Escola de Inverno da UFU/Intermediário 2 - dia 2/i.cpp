/*input
17
11
4
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

#define MAXN 30100
ll dp[MAXN];
int v[] = {1, 5, 10, 25, 50};


int main(){
	int n;
	dp[0] = 1;
	for(int i = 0; i < 5; i++)
		for(int j = v[i]; j <= MAXN; j++)
			dp[j] += dp[j-v[i]];

	while(cin >> n){
		if(dp[n] == 1)
			printf("There is only %lld way to produce %d cents change.\n", dp[n], n);
		else
			printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
	}
	return 0;
}