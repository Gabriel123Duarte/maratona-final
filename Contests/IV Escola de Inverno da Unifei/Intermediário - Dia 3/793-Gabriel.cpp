/*input
2

10
c 1 5
c 2 7
q 7 1
c 3 9
q 9 6
c 2 5
q 7 5

1
q 1 1
c 1 1
q 1 1
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

#define sz 100100
int p[sz];
void init(int n){
	for(int i = 0; i < n; i++)
		p[i] = i;
}

int find(int i){
	return p[i] == i ? i : p[i] = find(p[i]);
}

void merge(int i, int j){
	p[find(i)] = p[find(j)];
}

int main(){
	int t;
	cin >> t;
	string print;
	while(t--){
		int q, u, v;
		char type;

		cout << print;
		print = "\n";

		int succ = 0, unsucc = 0;
		cin >> q;
		init(q);
		cin.ignore();
		string s;
		while(getline(cin, s), s.size()){

			stringstream ss(s);
			ss >> type;
			ss >> u;
			ss >> v;
			if(type == 'c')
				merge(u-1, v-1);
			else{
				if(find(u-1) == find(v-1))
					succ++;
				else
					unsucc++;
			}
		}

		printf("%d,%d\n", succ, unsucc);
	}
	return 0;
}