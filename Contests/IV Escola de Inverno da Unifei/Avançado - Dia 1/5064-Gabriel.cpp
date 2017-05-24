/*input
4
1 4
2 3 5
1 2
3 4 5 6
2 4 13
3 4 13 888
3 012 345 6789
2 12345 67890
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

#define MAXN 110
#define ALPHA 10

int trie[MAXN][ALPHA];
int term[MAXN];
int failure[MAXN];
int cnt;
ll dp[20][MAXN][2][2];

void insert(string s){
	int node = 0;
	for(auto c : s){
		if(!trie[node][c-'0'])
			trie[node][c-'0'] = cnt++;
		node = trie[node][c-'0'];
	}
	term[node] = 1;
}

void aho(){
	queue<int> q;

	for(int i = 0; i < ALPHA; i++){
		if(trie[0][i]){
			failure[trie[0][i]] = 0;
			q.push(trie[0][i]);
		}
	}

	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = 0; i < ALPHA; i++){
			if(trie[u][i]){
				int v = failure[u];
				while(v && !trie[v][i])
					v = failure[v];
				v = trie[v][i];
				failure[trie[u][i]] = v;
				term[trie[u][i]] |= term[v];
				q.push(trie[u][i]);
			}	
		}
	}
}

int next(int node, int c){
	while(node && !trie[node][c])
		node = failure[node];
	return trie[node][c];
}

string toString(ll x){
	stringstream ss;
	ss << x;
	return ss.str();
}

string str;
ll solve(int id, int node, int pref, int leftZero){
	if(term[node])
		return 0;
	if(id == str.size())
		return 1;
	
	ll &ans = dp[id][node][pref][leftZero];
	if(ans != -1)
		return ans;
	ans = 0;
	
	for(int i = 0; i < ALPHA; i++){
		if(pref){
			if(i > (str[id]-'0'))
				continue;
			int x = node;
			if(!(!i && leftZero))
				x = next(node, i);
			ans += solve(id+1, x, !(i < (str[id]-'0')), !i & leftZero);
		}
		else{
			int x = node;
			if(!(!i && leftZero))
				x = next(node, i);
			ans += solve(id+1, x, 0, !i & leftZero);
		}
	}
	return ans;
}

char aux[30];
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int k;
		scanf("%d", &k);
		string s;

		memset(trie, 0, sizeof trie);
		memset(term, 0, sizeof term);
		memset(failure, 0, sizeof failure);
		cnt = 1;
		int zero = 0;
		while(k--){
			scanf("%s", aux);
			s = string(aux);
			insert(s);
			zero |= s == "0";
		}
		aho();
		int n;
		scanf("%d", &n);
		bool first = 1;
		while(n--){
			ll num;
			scanf("%lld", &num);
			num++;
			ll l = 0, r = 10000000000LL, ans;
			while(l <= r){
				ll mid = (l+r)/2;
				str = toString(mid);
				memset(dp, -1, sizeof dp);
				ll aux = solve(0, 0, 1, 1) - zero;
				if(aux < num)
					l = mid+1;
				else if(aux > num)
					r = mid-1;
				else{
					ans = mid;
					break;
				}
			}

			if(!first)
				printf(" ");
			first = 0;
			printf("%lld", ans);
		}
		puts("");
	}
	return 0;
}