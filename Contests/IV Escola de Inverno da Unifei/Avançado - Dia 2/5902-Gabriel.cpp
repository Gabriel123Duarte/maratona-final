/*input
2
3 3
3 1 1
5 3
4 4 5
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

#define MAXN 100100
int n, m, root;
int v[MAXN];
deque<int> blocks[MAXN];
unordered_map<int, int> nums[MAXN];

void create(){
	int px = 0;
	for(int i = 0; i < n; i++){
		for(auto x : blocks[i])
			v[px++] = x;
		blocks[i].clear();
		nums[i].clear();
	}
	
	for(int i = 0; i < n; i++){
		nums[i/root][v[i]] = 1;
		blocks[i/root].pb(v[i]);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
			blocks[i].clear();
		
		root = sqrt(n) + 1;
		for(int i = 1; i <= n; i++)
			blocks[0].pb(i);
		

		create();
		int x;
		bool first = 1;
		for(int i = 0; i < m; i++){
			if(blocks[0].size() > 3*root)
				create();
			cin >> x;
			int b = 0;
			int sz = 0;
			while(!nums[b][x]){
				sz += blocks[b].size();
				b++;
			}

			for(int i = 0; i < blocks[b].size(); i++){
				if(blocks[b][i] != x)
					sz++;
				else{
					if(!first)
						printf(" ");
					first = 0;
					printf("%d", sz);

					blocks[b].erase(blocks[b].begin() + i);
					nums[b][x] = 0;
					nums[0][x] = 1;
					blocks[0].push_front(x);
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}