/*input
4 6
-2 6 0 -1
C 1 10
P 1 4
C 3 7
P 2 2
C 4 -5
P 1 4
5 9
1 5 -2 4 3
P 1 2
P 1 5
C 4 -5
P 1 5
P 4 5
C 3 0
P 1 5
C 4 -5
C 4 -5
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
#define m ((l + r) / 2)

int vet[MAX], tree[MAX * 4];

int get(int x){
	if (x > 0)
		return 1;
	if (x < 0)
		return -1;
	return 0;
}

void build(int id, int l, int r){
	if (l == r){
		tree[id] = vet[l];
		return;
	}

	build(id * 2,     l,     m);
	build(id * 2 + 1, m + 1, r);
	tree[id] = tree[id * 2] * tree[id * 2 + 1];
}

void update(int id, int l, int r, int p, int v){
	if (p > r || p < l)
		return;

	if (l == r && r == p){
		tree[id] = v;
		return;
	}

	update(id * 2,     l,     m, p, v);
	update(id * 2 + 1, m + 1, r, p, v);
	tree[id] = tree[id * 2] * tree[id * 2 + 1];
}

int get(int id, int l, int r, int i, int j){
	if (j < l || i > r)
		return 1;

	if (l >= i && r <= j)
		return tree[id];

	return get(id * 2, l, m, i, j) * get(id * 2 + 1, m + 1, r, i, j); 
}

char ans(int x){
	if (x == 1) return '+';
	if (x == -1) return '-';
	if (x == 0) return '0';
}

int main(){

	int n, k, x, y;

	while(scanf("%d %d", &n, &k) != EOF){
		
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			vet[i] = get(x);
		}
		
		build(1, 0, n - 1);
		char c;
		
		while(k--){
			cin >> c >> x >> y;

			if (c == 'C'){
				x--;
				update(1, 0, n - 1, x, get(y));
			}else{
				x--; y--;
				cout << ans(get(1, 0, n - 1, x, y));
			}
		}

		cout << endl;
	}

	return 0;
}