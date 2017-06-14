/*input
2 
SuperGame::PROGRAM 1 
SuperServer42::PROGRAM 
SuperServer42::PROGRAM 1 
SuperServer42::PROGRAM 
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

vector<int> graph[500];
vector<int> vis;

void dfs(int u){
	vis[u] = 1;
	for(auto v : graph[u])
		if(!vis[v])
			dfs(v);
}

int main(){
	int n;
	cin >> n;
	map<string, int> mp;
	vector<int> starts;
	int idx = 0;
	string s, s2;
	int total;

	cin.ignore();
	for(int i = 0; i < n; i++){
		cin >> s >> total;

		if(mp.find(s) == mp.end())
			mp[s] = idx++;
		if(s.find("PROGRAM") != string::npos)
			starts.pb(mp[s]);

		while(total--){
			cin >> s2;
			
			if(mp.find(s2) == mp.end())
				mp[s2] = idx++;
			//if(s2.find("PROGRAM") != string::npos)
			//	starts.pb(mp[s2]);
			
			graph[mp[s2]].pb(mp[s]);

		}
	}	

	vis.assign(idx, 0);
	for(auto x : starts)
		dfs(x);

	int ans = 0;
	for(int i = 0; i < idx; i++)
		ans += !vis[i];
	cout << ans << endl;
	return 0;
}	