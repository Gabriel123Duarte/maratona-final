/*input
20 3
3 8 10
20 4
2 3 8 10
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

ll v[1010];
ll dp[1010][1010];
int dpAux[1010][1010];
int n, k;

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
	while(scanf("%d %d", &k, &n) == 2){
		v[0] = 0;
		for(int i = 1; i <= n; i++)
			rd(v[i]);
		v[n+1] = k;

		for(int sz = 0; sz <= n+1; sz++){
            for(int i = 0; i+sz <= n+1; i++){ 
           		int j = i+sz;
                if(sz < 2){
                    dp[i][j] = 0;
                    dpAux[i][j] = i;
                    continue;
                }
                dp[i][j] = 1LL<<60;
                for (int x = dpAux[i][j-1]; x <= dpAux[i+1][j]; x++){
                    if(dp[i][j] > dp[i][x] + dp[x][j] + v[j] - v[i]){
                        dp[i][j] = dp[i][x] + dp[x][j] + v[j] - v[i];
                        dpAux[i][j] = x;
                    }
                }
            }
        }

		printf("%lld\n", dp[0][n+1]);
	}
	return 0;
}