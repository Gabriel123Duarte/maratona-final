/*input
3
a1 h8
a1 c2
h8 c3
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

int dx[] = {1,1,2,2,-1,-1,-2,-2};
int dy[] = {2,-2,1,-1,2,-2,1,-1};

bool ok(int i, int j){
	return !(i <= 0 || i > 8 || j <= 0 || j > 8);
}

int bfs(int x, int y, int a, int b){
	int dist[10][10];
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			dist[i][j] = 1<<30;
	dist[x][y] = 0;
	queue<ii> q;
	q.push({x, y});
	while(!q.empty()){
		x = q.front().fst, y = q.front().snd; q.pop();

		for(int i = 0; i < 8; i++){
			if(ok(x+dx[i], y+dy[i]) && dist[x+dx[i]][y+dy[i]] == 1<<30){
				dist[x+dx[i]][y+dy[i]] = 1 + dist[x][y];
				q.push({x+dx[i], y+dy[i]});
			}
		}
	}
	return dist[a][b];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		cout << bfs(a[1]-'0', a[0]-'a'+1, b[1]-'0', b[0]-'a'+1) << endl;
	}
	return 0;
}