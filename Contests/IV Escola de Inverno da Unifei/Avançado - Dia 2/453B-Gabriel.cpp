/*input
5
1 1 1 1 1
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

int n;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int bitPrime[70], factors[70];
int a[110], dp[110][1<<17], path[110][1<<17];

void pre(){
	for(int i = 0; i < 17; i++)
		bitPrime[i] = 1<<i;

	for(int i = 1; i <= 60; i++){
		int x = i;
		for(int j = 0; j < 17; j++){
			while(x % primes[j] == 0){
				factors[i] |= bitPrime[j];
				x /= primes[j];
			}
		}
	}
}

int solve(int id, int bit){
	if(id == n)
		return 0;
	int &ans = dp[id][bit];
	if(ans != -1)
		return ans;
	ans = 1<<30;
	for(int i = 0; i <= 60; i++)
		if(!(bit&factors[i])){
			int aux = abs(i-a[id]) + solve(id+1, bit|factors[i]);
			if(aux < ans){
				ans = aux;
				path[id][bit] = i;
			}
		}
	return ans;
}

int main(){
	pre();
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	memset(dp, -1, sizeof dp);
	solve(0, 0);

	int id = 0, bit = 0;
	while(id != n){
		int x = path[id][bit];
		cout << x << " ";
		id++;
		bit |= factors[x];
	}
	cout << endl;
	return 0;
}