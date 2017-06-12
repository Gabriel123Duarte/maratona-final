/*input
1
4
a
aa
aaa
aaaa
4
4
race
car
ac
ecar
3
xyz
abac
aba
5
abc
ba
xab
x
bax
5
abc
ab
cba
ba
c
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
int trie[MAXN][26];
int isEnd[MAXN];
int dp[510][510];
int cnt;

void insert(string s){
	reverse(all(s));
	int cur = 0;
	for(auto c : s){
		if(!trie[cur][c-'a'])
			trie[cur][c-'a'] = cnt++;
		cur = trie[cur][c-'a'];
	}
	isEnd[cur]++;
}

ll solve(string s){
	ll ans = 0;
	int cur = 0;
	for(int i = 0; i < s.size(); i++){
		if(!trie[cur][s[i]-'a']){
			ans += isEnd[cur]*dp[min(i+1, (int)s.size()-1)][s.size()-1];
			return ans;
		}		
		ans += isEnd[cur]*dp[min(i+1, (int)s.size()-1)][s.size()-1];
		cur =  trie[cur][s[i]-'a'];
	}
	ans += isEnd[cur]*dp[s.size()-1][s.size()-1];
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++){
		printf("Case #%d: ", tt);

		int n;
		scanf("%d", &n);
		string s[n];

		cnt = 1;
		memset(trie, 0, sizeof trie);
		memset(isEnd, 0, sizeof isEnd);

		ll ans = 0;
		char str[550];
		for(int i = 0; i < n; i++){
			scanf("%s", str);
			s[i] = string(str);
			insert(s[i]);
		}

		for(int i = 0; i < n; i++){
			memset(dp, 0, sizeof dp);
			for(int j = 0; j < s[i].size(); j++)
				dp[j][j] = 1;

			for(int sz = 2; sz < s[i].size(); sz++)
				for(int j = 0; j + sz <= s[i].size(); j++)
					dp[j][j+sz-1] = s[i][j]==s[i][j+sz-1] & dp[j+1][j+sz-2];

			ans += solve(s[i]);// - dp[0][s[i].size()-1];
		}


		printf("%lld\n", ans);
	}
	return 0;
}