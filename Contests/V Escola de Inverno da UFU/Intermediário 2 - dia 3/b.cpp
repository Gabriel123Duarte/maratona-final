/*input
5
5 3 VERMELHO
4 2 LARANJA
1 1 VERDE
3 5 LARANJA
2 4 AZUL
3
10 10 LARANJA
5 10 VERDE
6 5 VERMELHO
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

vector<int> graph[1010];
int altura[1010], raio[1010];
string cor[1010];
int dp[1010];

bool ok(string a, string b){
	if(a == b)
		return 1;
	if(a == "VERMELHO"){
		if(b == "LARANJA" || b == "AZUL")
			return 1;
		return 0;
	}
	if(a == "LARANJA"){
		if(b == "AZUL" || b == "VERDE")
			return 1;
		return 0;
	}
	if(a == "AZUL"){
		if(b == "VERMELHO" || b == "VERDE")
			return 1;
		return 0;
	}
	if(a == "VERDE"){
		if(b == "VERMELHO" || b == "LARANJA")
			return 1;
		return 0;
	}
}

int solve(int u){
	if(dp[u] != -1)
		return dp[u];
	dp[u] = 0;
	for(auto v : graph[u])
		dp[u] = max(dp[u], altura[v]+solve(v));
	return dp[u];
}

int main(){
	int n;
	while(cin >> n, n){
		for(int i = 0; i <= n; i++)
			graph[i].clear();

		altura[0] = 0;
		for(int i = 1; i <= n; i++)
			cin >> altura[i] >> raio[i] >> cor[i];

		for(int i = 1; i <= n; i++){
			graph[0].pb(i);
			for(int j = 1; j <= n; j++)
				if(raio[i] > raio[j] && ok(cor[i], cor[j]))
					graph[i].pb(j);
		}
		
		memset(dp, -1, sizeof dp);
		cout << solve(0) << " centimetro(s)\n";

	}
	return 0;
}