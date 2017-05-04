/*input
great10
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

ll letters[300];

int main(){
	string s;
	cin >> s;
	for(auto c : s)
		letters[c]++;
	ll ans = 0;
	for(int i = 0; i < 300; i++)
		ans += letters[i]*letters[i];
	cout << ans << endl;
	return 0;
}