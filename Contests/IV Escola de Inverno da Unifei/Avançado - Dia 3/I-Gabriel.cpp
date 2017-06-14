/*input
2 1 
3 4 
4 4 4 
4 2 3
2 3 0
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
	int w, s;
	int x, y;
	cin >> w >> s;
	cin >> x >> y;

	int pieces[w][x];
	for(int i = 0; i < w; i++)
		for(int j = 0; j < x; j++)
			cin >> pieces[i][j];

	int cuts[x];
	for(int i = 0; i < s; i++){
		for(int j = 0; j < x; j++){
			int a;
			cin >> a;
			if(!i)
				cuts[j] = a;
			else
				cuts[j] = max(cuts[j], a);
		}
	}

	for(int i = 0; i < w; i++){
		for(int j = 0; j < x; j++)
			printf("%d ", min(pieces[i][j], y - cuts[j]));
		puts("");
	}
	return 0;
}