/*input
6
8 9 3 5 1 9
5
2 3 5
3 3 7
0 0 11
0 0 2
3 7 4
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back 

int main(){

	int n;

	scanf("%d", &n);

	int root = sqrt(n + 1);
	int vet[n + 1];
	vector<int> blocks[n + 1];

	for (int i = 1; i <= n; i++){
		scanf("%d", &vet[i]);
		blocks[i/root].pb(vet[i]);
	}

	for (int i = 1; i <= n; i++)
		sort(blocks[i].begin(), blocks[i].end());

	int last_ans = 0;
	int q, a, b, c;
	scanf("%d", &q);

	while(q--){
		scanf("%d %d %d", &a, &b, &c);

		a ^= last_ans;
		b ^= last_ans;
		c ^= last_ans;

		int ans = 0;

		if (a < 1) a = 1;
		if (b > n) b = n;

		for (int i = a; i <= b; i++){
			if (a >= n/root && b <= n/root){
				auto it = upper_bound(blocks[i].begin(), blocks[i].end(), c);
				ans += (blocks[i].end() - it);
				i += root;
			}else
				ans += vet[i] > c;
		}

		printf("%d\n", ans);
		last_ans = ans;
	}

	return 0;
}