/*input
3
picanha 15
coracao 14
maminha 37
4
alcatra 17
linguica 13
asinha 5
pernil 23
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


int main (){
	int n, x;
	string s;
	vector <pair <int, string> > v;
	while(cin >> n){

		for(int i = 0; i < n; i++){
			cin >> s >> x;
			v.pb({x, s});
		}

		sort(all(v));
		for(int i = 0; i < n; i++){
			if(i + 1 == n)
				cout << v[i].snd << "\n";
			else
				cout << v[i].snd << " ";
		}
		v.clear();
	}
	return 0;
}