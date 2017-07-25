/*input
3
1 1
2 0
3 1
3 
1 1 
2 1 
3 1
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

#define MAXN 500100
ll p[MAXN], r[MAXN];
ll L[MAXN], R[MAXN];
ii tree[6*MAXN];
int parent[MAXN];
map<ll, ll> mp;

ii max(ii a, ii b){
	if(a.fst != b.fst)
		return a.fst > b.fst ? a : b;
	return a.snd < b.snd ? a : b;
}

void update(int idx, int l, int r, int x, int v, int p){
	if(r < x || l > x)
		return;
	if(l == r && r == x){
		tree[idx] = ii(v, p);
		return;
	}
	update(idx*2, l, (l+r)/2, x, v, p);
	update(idx*2+1, (l+r)/2+1, r, x, v, p);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

ii get(int idx, int l, int r, int x, int y){
	if(l > y || r < x)
		return ii(-1, -1);
	if(l >= x && r <= y)
		return tree[idx];
	return max(get(idx*2, l, (l+r)/2, x, y), get(idx*2+1, (l+r)/2+1, r, x, y));
}


int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> p[i] >> r[i];
		mp[p[i]-r[i]] = mp[p[i]] = mp[p[i]+r[i]] = 1;
	}

	int idx = 0;
	for(auto &m : mp)
		m.snd = idx++;

	for(int i = 0; i < n; i++){
		L[i] = mp[p[i]-r[i]];
		R[i] = mp[p[i]+r[i]];
		p[i] = mp[p[i]];
	}

	int ans[n];
	ans[0] = 1;
	update(1, 0, idx-1, p[0], 1, 0);
	for(int i = 0; i < n; i++)
		parent[i] = i;

	for(int i = 1; i < n; i++){
		ii x = get(1, 0, idx-1, L[i], R[i]);
		ans[i] = 1+x.fst;
		parent[i] = x.snd;
		update(1, 0, idx-1, p[i], ans[i], i);
	}

	int big = 0, id = 0;
	for(int i = 0; i < n; i++){
		if(ans[i] > big){
			big = ans[i];
			id = i;
		}
	}
	
	int px = id;
	vector<int> rec;
	for(int i = 0; i < big; i++){
		rec.pb(px+1);
		px = parent[px];
	}

	reverse(all(rec));
	cout << big << endl;
	for(int i = 0; i < rec.size(); i++)
		cout << rec[i] << " ";
	cout << "\n";
	return 0;
}