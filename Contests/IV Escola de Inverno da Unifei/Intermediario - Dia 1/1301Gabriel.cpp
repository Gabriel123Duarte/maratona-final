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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> ii;

#define MAXN 100010

int v[MAXN], tree[4*MAXN];

int get(int x){
	if(x < 0)
		return -1;
	if(x > 0)
		return 1;
	return 0;
}

void build(int idx, int l, int r){
	if(l == r){
		tree[idx] = v[l];
		return;
	}
	build(idx*2, l, (l+r)/2);
	build(idx*2+1, (l+r)/2+1, r);
	tree[idx] = tree[idx*2] * tree[idx*2+1];
}



void update(int idx, int l, int r, int p, int v){
	if(l > p || r < p)
		return;
	if(l == r && r == p){
		tree[idx] = v;
		return;
	}
	update(idx*2, l, (l+r)/2, p, v);
	update(idx*2+1, (l+r)/2+1, r, p, v);
	tree[idx] = tree[idx*2] * tree[idx*2+1];
}

int get(int idx, int l, int r, int i, int j){
	if(l > j || r < i)
		return 1;
	if(l >= i && r <= j)
		return tree[idx];
	return get(idx*2, l, (l+r)/2, i, j) * get(idx*2+1, (l+r)/2+1, r, i, j);
}

int main(){
	int n, k;
	while(cin >> n >> k){

		for(int i = 0; i < n; i++){
			cin >> v[i];
			v[i] = get(v[i]);
		}
		build(1, 0, n-1);
		
		char c;
		int x, y;
		while(k--){
			cin >> c >> x >> y;
			if(c == 'C'){
				x--;
				update(1, 0, n-1, x, get(y));
			}
			else{
				int ans = get(1, 0, n-1, x-1, y-1);
				printf("%c", ans == 1 ? '+' : !ans ? '0' : '-');
			}
		}
		cout << "\n";
	}
	return 0;
}