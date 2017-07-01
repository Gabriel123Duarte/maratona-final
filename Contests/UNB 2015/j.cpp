/*input
5
maratonaicpc
maraton
programacao
progress
inputs
3
marat
programacao
outputs
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

int trie[101000][26];
int maxi[101000];
int total[101000];
int cnt;

void add(string s){
	int cur = 0;
	for(auto c : s){
		if(!trie[cur][c-'a'])
			trie[cur][c-'a'] = cnt++;
		cur = trie[cur][c-'a'];		
		maxi[cur] = max(maxi[cur], (int)s.size());
		total[cur]++;
	}
}

ii get(string s){
	int cur = 0;
	for(auto c : s){
		if(!trie[cur][c-'a'])
			return ii(-1, -1);
		cur = trie[cur][c-'a'];
	}
	return ii(maxi[cur], total[cur]);
}

int main(){
	int n;
	while(cin >> n){
		memset(trie, 0, sizeof trie);
		memset(maxi, 0, sizeof maxi);
		memset(total, 0, sizeof total);

		cnt = 1;
		string s;
		for(int i = 0; i < n; i++){
			cin >> s;
			add(s);
		}

		int q;
		cin >> q;
		while(q--){
			cin >> s;
			ii ans = get(s);
			if(ans.fst == -1)
				printf("-1\n");
			else
				printf("%d %d\n", ans.snd, ans.fst);
		}
	}
	return 0;
}