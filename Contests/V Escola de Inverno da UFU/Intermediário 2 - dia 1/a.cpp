/*input
4
100 150 90 170
3
2 1 3
1 2 50
2 2 4
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

#define MAXN 100100
int v[MAXN];
ii tree[4*MAXN];

ii op(ii a, ii b){
	a.fst = min(a.fst, b.fst);
	a.snd = max(a.snd, b.snd);
	return a;
}

void build(int idx, int l, int r){
	if(l == r){
		tree[idx] = ii(v[l], v[l]);
		return;
	}
	build(idx*2, l, (l+r)/2);
	build(idx*2+1, (l+r)/2+1, r);
	tree[idx] = op(tree[idx*2], tree[idx*2+1]);
}

void update(int idx, int l, int r, int x, int v){
	if(l > x || r < x)
		return;
	if(l == r && l == x){
		tree[idx] = ii(v, v);
		return;
	}
	update(idx*2, l, (l+r)/2, x, v);
	update(idx*2+1, (l+r)/2+1, r, x, v);
	tree[idx] = op(tree[idx*2], tree[idx*2+1]);
}

ii get(int idx, int l, int r, int x, int y){
	if(l > y || r < x)
		return ii(1<<30, -1<<30);
	if(l >= x && r <= y)
		return tree[idx];
	return op(get(idx*2, l, (l+r)/2, x, y), get(idx*2+1, (l+r)/2+1, r, x, y));
}

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		for(int i = 0; i < n; i++)
			scanf("%d", v+i);

		build(1, 0, n-1);
		int q, type, x, y;
		scanf("%d", &q);
		while(q--){
			scanf("%d %d %d", &type, &x, &y);
			if(type == 1)
				update(1, 0, n-1, x-1, y);
			else{
				ii ans = get(1, 0, n-1, x-1, y-1);
				printf("%d\n", ans.snd - ans.fst);
			}
		}
	}
	return 0;
}