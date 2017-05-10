/*input
5 6 8 5 2 6
2 25 62
0
*/

#include <bits/stdc++.h>

using namespace std;

int n, c[110], memo[110][1010][1010];

int solve(int id, int g1, int g2){
	
	if (id == n)
		return abs(g1 - g2);

	int &ans = memo[id][g1][g2];

	if (ans != -1)
		return ans;

	ans = 1<<30;

	ans = min(solve(id + 1, g1 + c[id], g2), solve(id + 1, g1, g2 + c[id]));

	return ans;
}

int main(){

	int caso = 0;

	while(scanf("%d", &n), n){
		caso++;

		for (int i = 0; i < n; i++)
			cin >> c[i];

		memset(memo, -1, sizeof memo);

		printf("Case %d: ", caso);
		
		cout << solve(0, 0, 0) << endl;
	}

	return 0;
}