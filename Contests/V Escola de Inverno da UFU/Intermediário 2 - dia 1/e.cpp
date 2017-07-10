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

int main(){
	int n;
	scanf("%d", &n);
	int v[n];
	for(int i = 0; i < n; i++){
		scanf("%d", v+i);
		update(i+1, v[i]);
	}

	char type;
	int x;
	while(scanf(" %c %d", &type, &x) == 2){
		if(type == 'a')
			update(x, -v[x-1]);
		else
			printf("%d\n", get(x-1));
	}
	return 0;
}