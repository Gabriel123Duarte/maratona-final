/*input
100
3 2 3 3 3 2 3 1 3 2 2 3 2 3 3 3 3 3 3 1 2 2 3 1 3 3 2 2 2 3 1 0 3 3 3 2 3 3 1 1 3 1 3 3 3 1 3 1 3 0 1 3 2 3 2 1 1 3 2 3 3 3 2 3 1 3 3 3 3 2 2 2 1 3 1 3 3 3 3 1 3 2 3 3 0 3 3 3 3 3 1 0 2 1 3 3 0 2 3 3
*/

#include <bits/stdc++.h>

using namespace std;

int N, memo[110][3], vet[110];

int solve(int n, int s){
	if (n == N)
		return 0;

	int &ans = memo[n][s];

	if (ans != -1)
		return ans;

	ans = 1 + solve(n + 1, 0);

	if (s != 1 && (vet[n] == 1 or vet[n] == 3))
		ans = min(ans, solve(n + 1, 1));
	if (s != 2 && (vet[n] == 2 or vet[n] == 3))
		ans = min(ans, solve(n + 1, 2));
		 	 
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	memset(memo, -1, sizeof memo);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> vet[i];

	cout << solve(0, 0) << endl;

	return 0;
}