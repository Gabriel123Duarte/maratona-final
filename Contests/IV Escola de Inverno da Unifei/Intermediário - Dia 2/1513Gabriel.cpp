/*input
5 5 2
.....
.P...
...P.
.....
..C..
4 6 2
.P##.P
..##..
..##..
..C...
0 0 0
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

#define INF 0x3f3f3f3f
int n, m, k;
char grid[110][110];
int val[110][110];
int aux[110][110];
int dist[20][20];
int dp[1<<17][17];
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

bool in(int i, int j){
	return !(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#');
}

void bfs(int i, int j){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			aux[i][j] = INF;
	aux[i][j] = 0;
	queue<ii> q;
	q.push({i, j});

	while(!q.empty()){
		int x = q.front().fst, y = q.front().snd; q.pop();
		
		if(val[x][y] != -1)
			dist[val[i][j]][val[x][y]] = aux[x][y];

		for(int i = 0; i < 8; i++){
			int nx = x+dx[i], ny = y+dy[i];
			if(in(nx, ny) && aux[nx][ny] == INF){
				q.push({nx, ny});
				aux[nx][ny] = 1+aux[x][y];
			}
		}
	}
}

int solve(int bit, int last){
	if(bit == (1<<k)-1)
		return dist[last][0];
	int &ans = dp[bit][last];
	if(ans != -1)
		return ans;
	ans = INF;
	for(int i = 0; i < k; i++)
		if(!(bit&(1<<i)))
			ans = min(ans, dist[last][i]+solve(bit|(1<<i), i));
	return ans;
}

int main(){
	while(cin >> n >> m >> k, n + m + k){
		for(int i = 0; i < n; i++)
			cin >> grid[i];

		int id = 1;
		memset(val, -1, sizeof val);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				dist[i][j] = INF;
				if(grid[i][j] == 'C')
					val[i][j] = 0;
				else if(grid[i][j] == 'P')
					val[i][j] = id++;
			}

		k++;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(val[i][j] != -1)
					bfs(i, j);

		memset(dp, -1, sizeof dp);
		cout << solve(1, 0) << endl;
	}
	return 0;
}