/*input
6 2
1 1 1 2 2 2
5
1 6
4 3
1 1
2 6
2 6
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

struct node{
	node *l, *r;
	int sum;
	node(){
		l = r = 0;
		sum = 0;
	}
};

deque<int> dq[MAXN];
vector<node*> roots;

void build(node *cur, int l, int r){
	if(l == r)
		return;
	cur->l = new node();
	cur->r = new node();
	build(cur->l, l, (l+r)/2);
	build(cur->r, (l+r)/2+1, r);
}

void update(node *last, node *cur, int l, int r, int x, int v){
	if(l > x || r < x)
		return;
	if(l == r && r == x){
		cur->sum += last->sum + v;
		return;
	}

	int mid = (l+r)/2;
	if(x <= mid){
		cur->l = new node();
		cur->r = last->r;
		update(last->l, cur->l, l, mid, x, v);
	}
	else{
		cur->r = new node();
		cur->l = last->l;
		update(last->r, cur->r, mid+1, r, x, v);
	}
	cur->sum = cur->l->sum + cur->r->sum;

}

int get(node *cur, int l, int r, int x, int y){
	if(l > y || r < x)
		return 0;
	if(l >= x && r <= y)
		return cur->sum;

	return get(cur->l, l, (l+r)/2, x, y) + get(cur->r, (l+r)/2+1, r, x, y);		
}

int main(){
	int n, k;
	cin >> n >> k;
	roots.pb(new node());
	build(roots.back(), 0, n);
	int x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		roots.pb(new node());
		update(roots[roots.size()-2], roots.back(), 0, n, i, 1);
		dq[x].pb(i);
		if(dq[x].size() > k){
			node *aux = new node();
			update(roots.back(), aux, 0, n, dq[x].front(), -1);
			roots[roots.size()-1] = aux;
			dq[x].pop_front();
		}
	}

	int last = 0;
	int q, l, r;
	cin >> q;
	while(q--){
		cin >> l >> r;
		l = ((l+last)%n)+1;
		r = ((r+last)%n)+1;
		if(l > r)
			swap(l, r);
		last = get(roots[r], 0, n, l, r);
		cout << last << endl;
	}
	return 0;
}