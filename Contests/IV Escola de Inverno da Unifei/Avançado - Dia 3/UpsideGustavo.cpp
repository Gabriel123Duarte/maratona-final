/*input
1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long 

bool is(ll x){
	if(x == 1)
		return 0;
	for(ll i = 2; i*i <= x; i++)
		if(x % i == 0)
			return 0; 
	return 1;
}

ll get(string s){
	ll ans = 0;
	for(auto c : s)
		ans = ans * 10 + (c-'0');
	return ans;
}

int main(){
	string s;
	cin >> s;
	for(auto c : s){
		if(c == '3' or c == '4' or c == '7'){
			puts("no");
			return 0;
		}
	}

	map<char, char> mp;
	mp['0'] = '0';
	mp['2'] = '2';
	mp['8'] = '8';
	mp['1'] = '1';
	mp['6'] = '9';
	mp['9'] = '6';
	mp['5'] = '5';
	string s2 = s;
	for(auto &c : s2)
		c = mp[c];
	reverse(s2.begin(), s2.end());
	
	puts(is(get(s)) & is(get(s2)) ? "yes" : "no");
	return 0;
}