/*input
3
2334 5 1256 4323 7687 3244 5678
1256 2 2334 7687
4323 5 2334 5678 6547 9766 9543
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
		map<int, vector<int> > friends;
		int x, m, y;
		while(n--){
			cin >> x >> m;
			friends[x] = vector<int>();
			while(m--){
				cin >> y;
				friends[x].pb(y);
			}
		}

		set<int> my;
		for(auto f : friends)
			for(auto x : f.snd)
				if(friends.find(x) == friends.end())
					my.insert(x);

		cout << my.size() << endl;
	}
	return 0;
}