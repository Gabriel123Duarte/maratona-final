/*input
4
100 1
15 15
20 5
1 100
*/

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<ll, ll> ii;

#define MAXN 50100
ll dp[MAXN];

struct hull{
	ll A[MAXN];
	ll B[MAXN];
	int len, ptr;
	hull(){
		len = ptr = 0;
	}
	void addLine(ll a, ll b){
		while(len >= 2 && (B[len-2] - B[len-1]) * (a-A[len-1]) >= (B[len-1]-b) * (A[len-1]-A[len-2]))
			len--;
		A[len] = a;
		B[len] = b;
		len++;
	}

	ll get(ll x){
		ptr = min(ptr, len-1);
		while(ptr+1 < len && A[ptr+1]*x+B[ptr+1] <= A[ptr]*x + B[ptr]) // Inserir o A negado para máximo
			ptr++;
		return A[ptr]*x + B[ptr];
	}
};

int main(){
	int n;
	cin >> n;
	ii v[n];
	for(int i = 0; i < n; i++)
		cin >> v[i].fst >> v[i].snd;

	sort(v, v+n);
	ii vFinal[n];
	int cnt = 0;

	for(int i = 0 ; i < n; i++){
		while(cnt > 0 && vFinal[cnt-1].snd <= v[i].snd)
			cnt--;
		vFinal[cnt++] = v[i];
	}
		
	n = cnt;
	/*
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		dp[i] = 1LL<<60;
		for(int j = 1; j <= i; j++){
			dp[i] = min(dp[i], dp[j-1] + vFinal[j-1].snd*vFinal[i-1].fst);
		}
	}

	*/
	hull *cht = new hull();
	cht->addLine(vFinal[0].snd, 0);
	for(int i = 1; i <= n; i++){
		dp[i] = cht->get(vFinal[i-1].fst);
		if(i < n)
			cht->addLine(vFinal[i].snd, dp[i]);
	}
	cout << dp[n] << endl;
	return 0;
}