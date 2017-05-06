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

#define MAX 100010

int bits[MAX];

void update(int x, int v){
	for(; x < MAX; x+=x&-x)
		bits[x] += v;
}

int get(int x){
	int ans = 0;
	for(; x; x-=x&-x)
		ans += bits[x];
	return ans;
}

int get(int i, int j){
	return get(j) - get(i - 1);
}

int main(){

	int n, p;

	scanf("%d", &n);
	memset(bits, 0, sizeof bits);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &p);
		update(i + 1, p);
	}

	char c;
	int x;
	
	while(cin >> c >> x){
		if (c == 'a')
			update(x, -get(x, x));
		else
			cout << get(1, x - 1) << endl;
	}

	return 0;
}
