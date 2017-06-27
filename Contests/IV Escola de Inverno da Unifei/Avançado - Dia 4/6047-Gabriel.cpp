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


int main(){
	int t;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++){
		printf("Case #%d: ", tt);

		int n;
		scanf("%d", &n);
		string s[n];


		ll ans = 0;
		char str[550];
		for(int i = 0; i < n; i++){
			scanf("%s", str);
			s[i] = string(str);
			
			
		}


		printf("%lld\n", ans);
	}
	return 0;
}