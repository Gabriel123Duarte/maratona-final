/*input
5 20 2 3
2 5 8 11 15
4 20 12 9
1 2 3 13
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

int n, c, t1, t2;
int dp[1010];
deque<int> v;

int solve(int id){
	if(id == n)
		return 0;
	int &ans = dp[id];
	if(ans != -1)
		return ans;
	ans = 0;
	int aux = 0;
	for(int i = id+1; i < n; i++){
		if(v[id] + t1 >= v[i])
			aux++;
		else
			break;
	}

	ans = t1 + solve(id + aux + 1);
	aux = 0;
	for(int i = id+1; i < n; i++){
		if(v[id] + t2 >= v[i])
			aux++;
		else
			break;
	}	
	ans = min(ans, t2 + solve(id + aux + 1));
	return ans;	
}

int main(){
	while(cin >> n >> c >> t1 >> t2){
		
		int furos[n];
		for(int i = 0; i < n; i++)
			cin >> furos[i];

		int ans = 1<<30;
		for(int i = 0; i < n; i++){
			memset(dp, -1, sizeof dp);
			v.clear();

			for(int j = i; j < n; j++)
				v.push_back(furos[j]);
			for(int j = 0; j < i; j++)
				v.push_back(furos[j]);

			for(int i = 0; i < n - 1; i++)
				if(v[i] > v[i + 1])
					v[i + 1] = v[i] + c - v[i] + v[i + 1];

			ans = min(ans, solve(0));
		}

		cout << ans << endl;
	}
	return 0;
}