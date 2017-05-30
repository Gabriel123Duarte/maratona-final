/*input
4
P1R2P2R1P1R2
P1P2R2R2P2R1
R1P2R1P2
P1P2P1R2R1P2R1R2
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
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		printf("Caso %d: ", tt);

		string s;
		cin >> s;
		stack<int> st;
		bool ok = 1;
		string s2;
		for(int i = 0; i < s.size(); i+=2){
			s2 = s[i];
			s2 += s[i+1];

			if(s2[0] == 'P'){
				if(s2[1] == '1')
					st.push(0);
				else
					st.push(1);
			}
			else{
				if(st.empty())
					ok = 0;
				else{
					if(s2[1] == '1'){
						if(st.top() == 1)
							st.pop();
						else
							ok = 0;
					}
					else{
						if(st.top() == 0)
							st.pop();
						else
							ok = 0;
					}
				}
			}
		}
		if(!st.empty())
			ok = 0;
		puts(ok ? "Sim" : "Nao");
	}
	return 0;
}