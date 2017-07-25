/*input
8 3
0 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1
1 1 0 1 1 1 1 1
1 1 1 0 1 1 1 1
1 1 1 1 0 1 1 1
1 1 1 1 1 0 1 1
1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 0

3 2
0 2 0
2 0 3
0 3 0
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

int dp[801][4001];
int pref[4001][4001];

int get(int i, int j){
	return (pref[j][j] - pref[i-1][j] - pref[j][i-1] + pref[i-1][i-1])/2;
}

void solve(int i, int left, int right, int kleft, int kright){
	if(left > right)
		return;

	int jmid = (right+left)/2;
	dp[i][jmid] = 1<<30;
	int bestk = -1;
	for(int k = kleft; k <= min(kright, jmid); k++){
		if(dp[i-1][k] + get(k+1, jmid) < dp[i][jmid]){
			dp[i][jmid] = dp[i-1][k] + get(k+1, jmid);
			bestk = k;
		}
	}

	solve(i, left, jmid-1, kleft, bestk);
	solve(i, jmid+1, right, bestk, kright);		
}


template<class num>inline void rd(num &x)
{
    char c;
    while(isspace(c = getchar()));
    bool neg = false;
    if(!isdigit(c))
        neg=(c=='-'), x=0;
    else
        x=c-'0';
    while(isdigit(c=getchar()))
        x=(x<<3)+(x<<1)+c-'0';
    if(neg)
        x=-x;
}

int main(){
	int n, k;
	rd(n);
	rd(k);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			rd(pref[i][j]);
			pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
		}

	
	for(int i = 1; i <= n; i++)
		dp[1][i] = get(1, i);

	for(int i = 2; i <= k; i++)
		solve(i, 1, n, 1, n);

	printf("%d\n", dp[k][n]);
	return 0;
}