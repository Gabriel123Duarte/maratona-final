/*input
4
24 1
4358 754
305 794
0 0
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
	while(n--){
		string a, b;
		cin >> a >> b;
		reverse(all(a));
		reverse(all(b));
		if(a.size() > b.size())
			swap(a, b);
		while(b.size() != a.size())
			a = "0"+a;


		int carry = 0;
		for(int i = a.size()-1; i >= 0; i--){
			int x = carry + a[i]-'0' + b[i]-'0';
			a[i] = (x%10)+'0';
			carry = x >= 10;
		}

		if(carry)
			a = "1" + a;
		reverse(all(a));

		bool ok = 0;
		for(int i = 0; i < a.size(); i++){
			if(a[i] == '0'){
				if(ok)
					cout << a[i];
			}
			else{
				cout << a[i];
				ok = 1;
			}
		}

		if(!ok)
			cout << "0";
		puts("");
	}
	return 0;
}