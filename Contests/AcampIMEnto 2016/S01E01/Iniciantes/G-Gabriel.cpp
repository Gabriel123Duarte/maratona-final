/*input
6
first
first
second
second
third
third
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
	int n;
	cin >> n;
	unordered_map<string, int> mp;

	string s;
	while(n--){
		cin >> s;
		if(!mp[s])
			puts("OK");
		else
			printf("%s%d\n", s.c_str(), mp[s]);
		mp[s]++;
	}

	return 0;
}