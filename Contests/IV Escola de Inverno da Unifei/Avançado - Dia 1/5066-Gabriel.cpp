/*input
2
3 3 5 3 55
XXXXX
X..UX
XSXXX
XXXXX
XU.DX
XXXXX
XXXXX
XD..X
XXXXX
1 2 3 10
3 2 3 50
3 2 4 60
2 2 6 4 27
......
S..U..
......
...D..
1 2 3 20
1 2 5 50
1 2 6 50
2 1 1 90
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
typedef pair<int, ii> iii;

#define INF 1<<27

int l, h, w, n, s;
char grid[15][110][110];
int dist[15][110][110];
int val[110], weight[110];
int dp[110][11000];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool inGrid(int g, int i, int j){
	return !(i < 0 || i >= h || j < 0 || j >= w || grid[g][i][j] == 'X');
}

void bfs(int x, int y){
	for(int i = 0; i <= l; i++)
		for(int j = 0; j <= h; j++)
			for(int k = 0; k <= w; k++)
				dist[i][j][k] = INF;
	queue<iii> q;
	q.push({0, {x, y}});
	dist[0][x][y] = 0;
	while(!q.empty()){
		int a = q.front().fst, b = q.front().snd.fst, c = q.front().snd.snd;
		q.pop();

		for(int i = 0; i < 4; i++){
			if(inGrid(a, b+dx[i], c+dy[i]) && dist[a][b+dx[i]][c+dy[i]] == INF){
				dist[a][b+dx[i]][c+dy[i]] = dist[a][b][c] + 1;
				q.push({a, {b+dx[i], c+dy[i]}});
			}
		}
		if(grid[a][b][c] == 'U' && dist[a+1][b][c] == INF){
			dist[a+1][b][c] = dist[a][b][c] + 1;
			q.push({a+1, {b, c}});
		}
		if(grid[a][b][c] == 'D' && dist[a-1][b][c] == INF){
			dist[a-1][b][c] = dist[a][b][c] + 1;
			q.push({a-1, {b, c}});
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d %d", &l, &h, &w, &n, &s);

		for(int i = 0; i < l; i++)
			for(int j = 0; j < h; j++)
				scanf("%s", grid[i][j]);

		int px, py;
		for(int i = 0; i < l; i++)
			for(int j = 0; j < h; j++){
				for(int k = 0; k < w; k++){
					if(grid[i][j][k] == 'S'){
						px = j;
						py = k;
					}
				}
			}

		
		bfs(px, py);
		int f, r, c, p;
		for(int i = 0; i < n; i++){
			scanf("%d %d %d %d", &f, &r, &c, &p);
			weight[i] = 3*dist[f-1][r-1][c-1];
			val[i] = p;
		}

		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= s; j++){
				if(i == 0 || j == 0)
					dp[i][j] = 0;
				else if(weight[i-1] <= j)
					dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-weight[i-1]]);
				else
					dp[i][j] = dp[i-1][j];
			}

		printf("%d\n", dp[n][s]);
	}
	return 0;
}