/*input
abcd
aaaa
ababab
.
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

string T, P;
vector<int> B;
int n, m, ans;

void kmpPreprocess(){
	int i = 0, j = -1;
	B[0] = -1;
	while(i < m){
		while(j >= 0 && P[i] != P[j])
			j = B[j];
		i++;
		j++;
		B[i] = j;
	}
}

void kmpSearch(){
	int i = 0, j = 0;
	while(i < n){
		while(j >= 0 && T[i] != P[j])
			j = B[j];
		i++, j++;
		if(j == m){
			ans++;
			j = B[j];
		}
	}
}

int main(){
	while(cin >> P && P != "."){
		T = P + P;
		n = T.size();
		m = P.size();
		B.assign(n, 0);

		kmpPreprocess();
		ans = 0;
 		kmpSearch();

		printf("%d\n", ans - 1);
	}
	return 0;
}