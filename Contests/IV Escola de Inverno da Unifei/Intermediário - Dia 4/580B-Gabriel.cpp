/*input
5 100
0 7
11 32
99 10
46 8
87 54

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
	int n, d;
	cin >> n >> d;
	vector<ii> vet(n);
	for(int i = 0; i < n; i++)
		cin >> vet[i].fst >> vet[i].snd;

	sort(all(vet));
	ll prefix[n];
	for(int i = 0; i < n; i++){
		prefix[i] = vet[i].snd;
		if(i)
			prefix[i] += prefix[i-1];
	}

	ll ans = 0;
	for(int i = 0; i < n; i++){
		int l = i, r = n-1;
		while(l <= r){
			int mid = (l+r)/2;
			if(vet[mid].fst - vet[i].fst >= d)
				r = mid-1;
			else{
				ans = max(ans, prefix[mid] - (i == 0 ? 0 : prefix[i-1]));
				l = mid+1;
			}
			
		}
	}
	cout << ans << endl;
	return 0;
}