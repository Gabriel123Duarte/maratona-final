/*input
4
1 2 3 4
4
3 0
3 0 -1
0 1
2 1
*/

#include <bits/stdc++.h>

using namespace std;

#define meio ((l + r) / 2)
#define MAX 200010 

int vet[MAX], tree[MAX * 4], lazy[MAX * 4];

void build(int id, int l, int r){
	lazy[id] = 0;

	if (l == r){
		tree[id] = vet[l];
		return;
	}

	build(id * 2, l, meio);
	build(id * 2 + 1, meio + 1, r);
	tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
}

void update(int id, int l, int r, int i, int j, int v){
	if (lazy[id]){
		tree[id] += lazy[id];

		if (l != r){
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
		}

		lazy[id] = 0;
	}

	if (j < l || i > r)
		return;

	if (l >= i && r <= j){
		tree[id] += v;

		if (l != r){
			lazy[id * 2] += v;
			lazy[id * 2 + 1] += v;
		}

		return;
	}

	update(id * 2,     l,        meio, i, j, v);
	update(id * 2 + 1, meio + 1, r,    i, j, v);
	tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
}

int rmq(int id, int l, int r, int i, int j){
	if (lazy[id]){
		tree[id] += lazy[id];

		if (l != r){
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
		}

		lazy[id] = 0;
	}	

	if (j < l || i > r)
		return 1<<30;

	if (l >= i && r <= j)
		return tree[id];

	return min(rmq(id * 2, l, meio, i, j), rmq(id * 2 + 1, meio + 1, r, i, j));
}

int main(){
	ios::sync_with_stdio(false);
	int n;

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> vet[i];

	build(1, 0, n - 1);

	int m, x, y, v;

	cin >> m;
	string s;
	cin.ignore();
	while(m--){
		getline(cin, s);
		stringstream ss(s);
		vector<int> nums;

		while(ss >> x)
			nums.push_back(x);

		x = nums[0];
		y = nums[1];

		if (nums.size() == 3){
			v = nums[2];

			if (x > y){
				update(1, 0, n - 1, x, n - 1, v);
				update(1, 0, n - 1, 0, y, v);
			}else
				update(1, 0, n - 1, x, y, v);
		}else{
			int ans;
			if (x > y)
				ans = min(rmq(1, 0, n - 1, x, n - 1), rmq(1, 0, n - 1, 0, y));
			else
				ans = rmq(1, 0, n - 1, x, y);

			cout << ans << endl;
		}

	}

	return 0;
}