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

#define MAXN 100100
int v[MAXN];
int tree[4*MAXN];


void build(int idx, int l, int r){
	if(l == r){
		tree[idx] = v[l];
		return;
	}
	build(idx*2, l, (l+r)/2);
	build(idx*2+1, (l+r)/2+1, r);
	tree[idx] = tree[idx*2] * tree[idx*2+1];
}

void update(int idx, int l, int r, int x, int v){
	if(l > x || r < x)
		return;
	if(l == r && l == x){
		tree[idx] = v;
		return;
	}
	update(idx*2, l, (l+r)/2, x, v);
	update(idx*2+1, (l+r)/2+1, r, x, v);
	tree[idx] = tree[idx*2] * tree[idx*2+1];
}

int get(int idx, int l, int r, int x, int y){
	if(l > y || r < x)
		return 1;
	if(l >= x && r <= y)
		return tree[idx];
	return get(idx*2, l, (l+r)/2, x, y) * get(idx*2+1, (l+r)/2+1, r, x, y);
}

int val(int x){
	if(x < 0)
		return -1;
	if(x > 0)
		return 1;
	return 0;
}

int main(){
	int n, 		q;
	while(cin >> n >> q){
		for(int i = 0; i < n; i++){
			cin >> v[i];
			v[i] = val(v[i]); 
		}
		build(1, 0, n-1);
		char type;
		int x, y;
		while(q--){
			cin >> type >> x >> y;
			if(type == 'P'){
				int ans = get(1, 0, n-1, x-1, y-1);
				if(ans < 0)
					cout << "-";
				else if(ans > 0)
					cout << "+";
				else
					cout << "0";
			}
			else
				update(1, 0, n-1, x-1, val(y));
		}	
		cout << "\n";
	}
	return 0;
}