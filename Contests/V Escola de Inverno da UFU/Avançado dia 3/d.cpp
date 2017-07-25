/*input
6
form
formal
malformed
for
man
remake
3
cool
cool
old
0
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
	while(cin >> n){
		string x; 
		tr[0].clear();
		ns = cn = cd = cc = li = 0; e = -1; en = 1;
		for(int i = 0; i < n; i++){
			cin >> x;
			x += "$";
			s = x;
			for(int j = 0; j < s.size(); j++)
				add(i);
		}
	}
	return 0;
}

