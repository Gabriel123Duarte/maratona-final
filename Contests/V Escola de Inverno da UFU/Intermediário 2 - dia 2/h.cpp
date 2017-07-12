/*input
3
100
100
100
M 1 1
M 1 3
S 2 200
M 1 2
S 3 0
M 2 3
END
10
1
2
3
4
5
6
7
8
9
10
M 1 10
END
0
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

#define MAXN 200100
int bit[MAXN];

void update(int x, int v){
	for(; x < MAXN; x+=x&-x)
		bit[x] += v;
}

int get(int x){
	int ans = 0;
	for(; x; x-=x&-x)
		ans += bit[x];
	return ans;
}

int get(int i, int j){
	return get(j) - get(i-1);
}

int main(){
	int test = 1;
	int n;
	string print;
	while(cin >> n, n){
		memset(bit, 0, sizeof bit);

		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			update(i, x);
		}

		cout << print;
		print = "\n";
		string s;
		int x, y;
		printf("Case %d:\n", test++);
		while(cin >> s, s != "END"){
			cin >> x >> y;
			if(s[0] == 'S')
				update(x, -get(x, x)+y);
			else
				cout << get(x, y) << endl;
		}
	}
	return 0;
}