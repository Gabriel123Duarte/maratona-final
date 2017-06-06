/*input
3
EEE
E..
E.E
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
	int n;
	cin >> n;
	char grid[n][n];
	for(int i = 0; i < n; i++)
		cin >> grid[i];

	bool row = 0, column = 0;
	for(int i = 0; i < n; i++){
		int aux = 0;
		for(int j = 0; j < n; j++)
			aux += grid[i][j] == 'E';
		if(aux == n)
			row = 1;
	}

	for(int i = 0; i < n; i++){
		int aux = 0;
		for(int j = 0; j < n; j++)
			aux += grid[j][i] == 'E';
		if(aux == n)
			column = 1;
	}	

	if(row && column)
		return 0 * puts("-1");

	if(row || row+column == 0){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if(grid[j][i] == '.'){
					printf("%d %d\n", j+1, i+1);
					break;
				}
			}
	}
	else{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if(grid[i][j] == '.'){
					printf("%d %d\n", i+1, j+1);
					break;
				}
			}
	}
	return 0;
}