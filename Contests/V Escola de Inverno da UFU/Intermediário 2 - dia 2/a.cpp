/*input
5 6
40 55 45 55 70
C 2 4
C 1 5
A 1 3 10
C 3 4
A 4 4 20
C 1 5
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
ii tree[MAXN*4];
int lazy[4*MAXN];
int v[MAXN];

ii max(ii a, ii b){
	if(a.fst != b.fst)
		return a.fst > b.fst ? a : b;
	return a.snd < b.snd ? a : b;
}

void build(int idx, int l, int r){
	if(l == r){
		tree[idx] = ii(v[l], l+1);
		lazy[idx] = 0;
		return;
	}
	build(idx*2, l, (l+r)/2);
	build(idx*2+1, (l+r)/2+1, r);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
	lazy[idx] = 0;
}

void dolazy(int idx, int l, int r){
	if(lazy[idx]){
		tree[idx].fst += lazy[idx];
		if(l != r){
			lazy[idx*2] += lazy[idx];
			lazy[idx*2+1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
}

void update(int idx, int l, int r, int i, int j, int v){
	dolazy(idx, l, r);
	if(l > j || r < i)
		return;
	if(l >= i && r <= j){
		tree[idx].fst += v;
		if(l != r){
			lazy[idx*2] += v;
			lazy[idx*2+1] += v;
		}
		return;
	}
	update(idx*2, l, (l+r)/2, i, j, v);
	update(idx*2+1, (l+r)/2+1, r, i, j, v);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);	
}

ii get(int idx, int l, int r, int i, int j){
	dolazy(idx, l, r);
	if(l > j || r < i)
		return {-1<<30, 1<<30};
	if(l >= i && r <= j)
		return tree[idx];
	return max(get(idx*2, l, (l+r)/2, i, j), get(idx*2+1, (l+r)/2+1, r, i, j));
}

int main(){
	int n, q;
	while(scanf("%d %d", &n, &q) != EOF){
		for(int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		build(1, 0, n-1);
		char tipo;
		int x, y, w;
		while(q--){
			scanf(" %c %d %d", &tipo, &x, &y);
			if(tipo == 'C')
				printf("%d\n", get(1, 0, n-1, x-1, y-1).snd);
			else{
				scanf("%d", &w);
				update(1, 0, n-1, x-1, y-1, w);
			}
		}
	}
	return 0;
}