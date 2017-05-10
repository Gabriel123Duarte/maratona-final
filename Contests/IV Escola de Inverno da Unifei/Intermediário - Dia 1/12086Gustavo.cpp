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

#define MAX 200010

int bit[MAX];

void update(int x, int v){
	for(; x < MAX; x += x&-x)
		bit[x] += v;
}

int get(int x){
	int ans = 0;
	for (; x; x -= x&-x)
		ans += bit[x];
	return ans;
}

int get(int i, int j){
	return get(j) - get(i - 1);
}

int main(){
	ios::sync_with_stdio(false);
	int n, v, x, y, caso = 0;

	while(cin >> n, n){
		caso++;

		if (caso > 1)
			cout << endl;
		
		memset(bit, 0, sizeof bit);

		for(int i = 1; i <= n; i++){
			cin >> v;
			update(i, v);
		}

		string o;
		
		cout << "Case " << caso << ":" << endl;
		while(1){
			cin >> o;

			if (o == "END")
				break;

			cin >> x >> y;
			
			if (o == "S")
				update(x, (-get(x, x)) + y);
			else
				cout << get(x, y) << endl;
		}
	}	

	return 0;
}