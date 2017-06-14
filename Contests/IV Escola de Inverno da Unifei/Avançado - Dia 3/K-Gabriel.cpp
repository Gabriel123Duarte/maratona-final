/*input
151
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

ll ok(ll x){
	if(x == 1)
		return 0;
	for(ll i = 2; i*i <= x; i++)
		if(x % i == 0)
			return 0;
	return 1;
}

int main(){
	string s;
	cin >> s;
	map<char, char> mp;
	mp['0'] = '0';
	mp['2'] = '2';
	mp['5'] = '5';
	mp['8'] = '8';
	mp['1'] = '1';
	mp['6'] = '9';
	mp['9'] = '6';

	for(auto c : s)
		if(c == '3' || c == '4' || c == '7')
			return 0 * puts("no");

	string s2 = s;
	reverse(all(s2));
	for(auto &c : s2)
		c = mp[c];

	puts(ok(stoll(s)) & ok(stoll(s2)) ? "yes" : "no");
	return 0;
}
