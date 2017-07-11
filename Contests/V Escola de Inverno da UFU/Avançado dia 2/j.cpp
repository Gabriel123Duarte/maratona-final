/*input
3
GCTTTCGACGAT
GATCGAGCTTCGAA
GGTCTAGCTAAT
TCGA
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

char str[10100];

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		string v[n];
		for(int i = 0; i < n; i++){
			scanf("%s", str);
			v[i] = string(str);
		}

		string bug;
		scanf("%s", str);
		bug = string(str);

		for(int i = 0; i < n; i++){
			while(v[i].find(bug) != string::npos)
				v[i].replace(v[i].find(bug), bug.size(), "");
		}

	}
	return 0;
}