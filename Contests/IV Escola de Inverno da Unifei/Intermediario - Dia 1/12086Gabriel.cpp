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

#define MAXN 200010
int bit[MAXN];

int get(int x){
	int ans = 0;
	for(; x; x-=x&-x)
		ans += bit[x];
	return ans;
}

int get(int x, int y){
	return get(y) - get(x-1);
}

int update(int x, int v){
	for(; x < MAXN; x+=x&-x)
		bit[x] += v;
}

int main(){
	int n, caso = 1;
	string print = "";
	while(cin >> n, n){
		memset(bit, 0, sizeof bit);
		int x, y;
		for(int i = 0; i < n; i++){
			cin >> x;
			update(i+1, x);
		}

		cout << print;
		print = "\n";
		printf("Case %d:\n", caso++);

		string type;
		while(cin >> type, type != "END"){
			cin >> x >> y;
			if(type[0] == 'S'){
				update(x, -get(x, x));
				update(x, y);
			}
			else
				cout << get(x, y) << endl;
		}
	}
	return 0;
}