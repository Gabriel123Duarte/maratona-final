/*input
5
100
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

bool vis[2][550][550];
double dp[2][550][550];
const int N = 20;
int v[25] = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5, 20, 1};

double solve(int turn, int sum1, int sum2){
	if(!turn){
		if(sum1 == 0)
			return 1;
		if(sum2 == 0)
			return 0;
	}
	if(turn){
		if(sum2 == 0)
			return 1;
		if(sum1 == 0)
			return 0;
	}
	if(sum1 <= 20 && sum2 <= 20){
		if(turn == 0)
			return 0.136363636364;
		else
			return 0.909090909091;
	}

	double &ans = dp[turn][sum1][sum2];
	if(vis[turn][sum1][sum2])
		return ans;
	vis[turn][sum1][sum2] = 1;
	ans = 0;
	
	if(turn){
		for(int i = 0; i < N; i++){
			double p = (solve(turn^1, sum1, sum2-v[i] >= 0 ? sum2-v[i] : sum2) + 
				        solve(turn^1, sum1, sum2-v[i+1] >= 0 ? sum2-v[i+1] : sum2) + 
				        solve(turn^1, sum1, sum2-v[i+2] >= 0 ? sum2-v[i+2] : sum2)) / 3.0;
			ans = max(ans, 1-p);
		}
	}
	else{
		for(int i = 1; i <= N; i++)
			ans += 1-solve(turn^1, sum1-v[i] >= 0 ? sum1-v[i] : sum1, sum2);
		ans /= 20.0;
	}
	return ans;
}

int main(){
	int n;
	while(cin >> n, n)
		cout << fixed << setprecision(12) << solve(0, n, n) <<  " " << solve(1, n, n) << endl;
	return 0;
}