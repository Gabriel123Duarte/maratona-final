/*input
3
5
1 2 3 4 5
4
3 4 3 2
6
1 1 1 2 1 2
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
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		printf("Caso %d: ", tt);
		int n, x;
		cin >> n;
		set<int> st;
		while(n--){
			cin >> x;
			st.insert(x);
		}
		cout << st.size() << endl;
	}
	return 0;
}