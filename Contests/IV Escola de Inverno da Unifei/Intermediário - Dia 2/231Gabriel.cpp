/*input
389
207
155
300
299
170
158
65
-1
23
34
21
-1
-1
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
	int x;
	int caso = 1;
	string print = "";
	while(cin >> x, x != -1){
		vector<int> v;
		v.pb(x);
		while(cin >> x, x != -1)
			v.pb(x);

		reverse(all(v));
		set<int> lis;
		for(auto x : v){
			auto it = lis.lower_bound(x);
			if(it != lis.end())
				lis.erase(it);
			lis.insert(x);			
		}

		cout << print;
		print = "\n";
		cout << "Test #" << caso++ << ":\n";
		cout << "  maximum possible interceptions: " << lis.size() << endl;
	}
	return 0;
}