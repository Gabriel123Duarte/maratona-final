/*input
3 7
5 2
13 1
8 1
20 5
6 1
11 1
10 4
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
int bit[MAXN];

void update(int x){
	for(; x < MAXN; x+=x&-x)
		bit[x]++;
}

int get(int x){
	int ans = 0;
	for(; x; x-=x&-x)
		ans += bit[x];
	return ans;
}

int get(int x, int y){
	return get(y) - get(x-1);
}

int main(){
	int ip, m;
	while(scanf("%d %d", &ip, &m) != EOF){
		int ans = 0;
		memset(bit, 0, sizeof bit);
		int pc, na;
		while(m--){
			scanf("%d %d", &pc, &na);
			int val = get(max(1, pc - ip), min(pc + ip, MAXN-1));
			if(val <= na){
				ans++;
				update(pc);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}