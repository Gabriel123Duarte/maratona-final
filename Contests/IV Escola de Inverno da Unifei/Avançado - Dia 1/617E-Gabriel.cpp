/*input
6 2 3
1 2 1 1 0 3
1 6
3 5
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

#define MAXN 1123456
#define BLOCK 316

int n, m, k;
ll a[MAXN], pref[MAXN];
ll freq[MAXN];
ll resp;

struct query{
	int l, r, id;
	bool operator<(query foo){
		if(l / BLOCK != foo.l / BLOCK)
			return l / BLOCK < foo.l / BLOCK;
		return r < foo.r;
	}
};

void add(int id){
	resp += freq[pref[id] ^ k];
	freq[pref[id] ^ k]++;
}

void remove(int id){
	freq[pref[id] ^ k]--;
	resp -= freq[pref[id] ^ k];
}

int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pref[i] = a[i] ^ pref[i-1];
	}

	query queries[m];
	for(int i = 0; i < m; i++){
		cin >> queries[i].l >> queries[i].r;
		queries[i].id = i;
	}
	
	sort(queries, queries + m);
	ll ans[m];
	freq[0] = 1;

	int curL = 1, curR = 1;
	for(int i = 0; i < m; i++){
		int l = queries[i].l, r = queries[i].r;

		while(curL < l){
			remove(curL);
			curL++;
		}
		while(curL > l){
			add(curL - 1);
			curL--;
		}
		while(curR <= r){
			add(curR);
			curR++;
		}
		while(curR > r + 1){
			remove(curR - 1);
			curR--;
		}

		ans[queries[i].id] = resp;
	}

	for(int i = 0; i < m; i++)
		cout << ans[i] << endl;
	return 0;
}