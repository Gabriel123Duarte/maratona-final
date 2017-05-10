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

int pontes[110], memo[110][1010];
int r, k;

int solve(int id, int s){
	if (s == k)
		return 1;

	if (s > k or id == r)
		return 0;

	int &ans = memo[id][s];

	if (ans != -1)
		return ans;

	ans = 0;

	ans += solve(id + 1, s + pontes[id]) | solve(id + 1, s);

	return ans;
}

int main(){

	while(scanf("%d %d", &r, &k) != EOF){

		int x, y;
		
		memset(pontes, 0, sizeof pontes);

		for (int i = 0; i < k; i++){
			cin >> x >> y;
			x--; y--;

			pontes[x]++; pontes[y]++;
		}

		memset(memo, -1, sizeof memo);

		if (solve(0, 0))
			cout << "S" << endl;
		else
			cout << "N" << endl;
	}

	return 0;
}
