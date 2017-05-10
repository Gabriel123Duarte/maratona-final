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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> ii;

#define MAXN 200010
int v[MAXN];
ll tree[4*MAXN], lazy[4*MAXN];

void build(int idx, int l, int r){
	lazy[idx] = 0;
	if(l == r){
		tree[idx] = v[l];
		return;
	}
	build(idx*2, l, (l+r)/2);
	build(idx*2+1, (l+r)/2+1, r);
	tree[idx] = min(tree[idx*2], tree[idx*2+1]);
}

ll get(int idx, int l, int r, int i, int j){
	if(lazy[idx]){
		tree[idx] += lazy[idx];
		if(l != r){
			lazy[idx*2] += lazy[idx];
			lazy[idx*2+1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if(r < i || l > j)
		return 1LL<<60;
	if(l >= i && r <= j)
		return tree[idx];
	return min(get(idx*2, l, (l+r)/2, i, j), get(idx*2+1, (l+r)/2+1, r, i, j));
}

void update(int idx, int l, int r, int i, int j, ll v){
	if(lazy[idx]){
		tree[idx] += lazy[idx];
		if(l != r){
			lazy[idx*2] += lazy[idx];
			lazy[idx*2+1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if(r < i || l > j)
		return;
	if(l >= i && r <= j){
		tree[idx] += v;
		if(l != r){
			lazy[idx*2] += v;
			lazy[idx*2+1] += v;
		}
		return;
	}
	update(idx*2, l, (l+r)/2, i, j, v);
	update(idx*2+1, (l+r)/2+1, r, i, j, v);
	tree[idx] = min(tree[idx*2], tree[idx*2+1]);
}

int main(){
 	ios::sync_with_stdio( false );
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];

	build(1, 0, n-1);

	int m;
	cin >> m;
	cin.ignore();
	string s;
	while(m--){
		getline(cin, s);
		int x, y, z;
		stringstream ss(s);
		vector<int> nums;
		while(ss >> x)
			nums.pb(x);
		
		x = nums[0];
		y = nums[1];

		if(nums.size() == 3){
			z = nums[2];
			if(x <= y){
				update(1, 0, n-1, x, y, z);
			}
			else{
				update(1, 0, n-1, x, n-1, z);
				update(1, 0, n-1, 0, y, z);
			}
		}
		else{
			if(x <= y)
				cout << get(1, 0, n-1, x, y) << "\n";
			else
				cout << min(get(1, 0, n-1, x, n-1), get(1, 0, n-1, 0, y)) << "\n";
		}
	}
	return 0;
}