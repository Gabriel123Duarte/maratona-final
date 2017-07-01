/*input
3
min
35 70 35
mean
10 74 181
eye
23 78 197
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
		string s;
		cin >> s;
		int r, g, b;
		cin >> r >> g >> b;
		printf("Caso #%d: ", tt);
		if(s == "max")
			printf("%d\n", max({r, g, b}));
		else if(s == "min")
			printf("%d\n", min({r, g, b}));
		else if(s == "mean")
			printf("%d\n", (int)((r+g+b)/3.0));
		else
			printf("%d\n", (int)(.3*r + .59*g + .11*b));
	}
	return 0;
}