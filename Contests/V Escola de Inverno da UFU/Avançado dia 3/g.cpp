/*input
2
GAUSS
GALOIS
ERDOS
EULER
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

int trie[30][30];
int cnt;

void insert(string s){
	int cur = 0;
	for(auto c : s){
		if(!trie[cur][c-'A'])
			trie[cur][c-'A'] = cnt++;
		cur = trie[cur][c-'A'];
	}
}

int get(string s){
	int cur = 0;
	int ans = 1;

	for(auto c : s){
		if(!trie[cur][c-'A'])
			return ans;
		cur = trie[cur][c-'A'];
		ans++;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	n *= 2;
	string v[n];
	for(int i = 0; i < n; i++)
		cin >> v[i];

	for(int i = 0; i < n; i++){
		cnt = 1;
		memset(trie, 0, sizeof trie);
		insert(v[i]);
		for(int j = i+1; j < n; j++){
			printf("%s %s %d\n", v[i].c_str(), v[j].c_str(), get(v[j]));
		}
	}

	return 0;
}