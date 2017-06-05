/*input
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###
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
typedef pair<int, ii> iii;

int l, r, c;
char grid[50][50][50];
int dist[50][50][50];
int startX, startY, startZ;
int endX, endY, endZ;

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

bool in(int x, int y, int z){
	return !(x < 0 || x >= l || y < 0 || y >= r || z < 0 || z >= c || grid[x][y][z] == '#');
}

int bfs(){
	for(int i = 0; i < l; i++)
		for(int j = 0; j < r; j++)
			for(int k = 0; k < c; k++)
				dist[i][j][k] = 1<<30;

	dist[startX][startY][startZ] = 0;
	queue<iii> q;
	q.push(iii(startX, ii(startY, startZ)));

	while(!q.empty()){
		int x = q.front().fst, y = q.front().snd.fst, z = q.front().snd.snd;
		q.pop();

		if(x == endX && y == endY && z == endZ)
			return dist[x][y][z];

		for(int i = 0; i < 6; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			int nz = z+dz[i];
			if(in(nx, ny, nz) && dist[nx][ny][nz] == 1<<30){
				dist[nx][ny][nz] = 1 + dist[x][y][z];
				q.push(iii(nx, {ny, nz}));
			}
		}
	}

	return -1;
}

int main(){
	while(cin >> l >> r >> c, l+r+c){
		for(int i = 0; i < l; i++){
			for(int j = 0; j < r; j++)
				cin >> grid[i][j];
			cin.ignore();
		}


		for(int i = 0; i < l; i++)
			for(int j = 0; j < r; j++)
				for(int k = 0; k < c; k++){
					if(grid[i][j][k] == 'S')
						startX = i, startY = j, startZ = k;
					else if(grid[i][j][k] == 'E')
						endX = i, endY = j, endZ = k;
				}			

		int ans = bfs();
		if(ans == -1)
			puts("Trapped!");
		else
			printf("Escaped in %d minute(s).\n", ans);
	}
	return 0;
}