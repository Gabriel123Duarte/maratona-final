/*input
aaaaaaaaaa
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

	long long ans = 0;
	string s;
	map<char, long long> m;

	cin >> s;

	for (int i = 0; i < s.size(); i++)
		m[s[i]]++;
	
	map<char, long long>::iterator it;

	for (it = m.begin(); it != m.end(); ++it)
		ans += (it->second) * (it->second);

	cout << ans << endl;
}	