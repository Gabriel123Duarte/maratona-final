/*input
10
1 2 3 4 5 4 3 2 1 2
a 9
? 10
a 2
a 5
? 6
a 6
? 10
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

int bit[MAXN + 10];

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
	return get(j) - get(i - 1);
}

int main(){
	int n;
	cin >> n;
	memset(bit, 0, sizeof bit);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		update(i + 1, x);
	}

	char c;
	int x;
	while(cin >> c >> x){
		if(c == 'a'){
			update(x, -get(x, x));
		}
		else
			cout << get(x - 1) << endl;
	}

	return 0;
}