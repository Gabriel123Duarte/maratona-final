/*input
pedra pedra pedra
pedra pedra papel
pedra pedra tesoura
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

bool ganha(string a, string b){
	if(a == "papel" && b == "pedra")
		return 1;
	if(a == "pedra" && b == "tesoura")
		return 1;
	if(a == "tesoura" && b == "papel")
		return 1;
	return 0;
}

int main(){
	string a, b, c;
	while(cin >> a >> b >> c){
		if(ganha(a, b) && ganha(a, c))
			printf("Os atributos dos monstros vao ser inteligencia, sabedoria...\n");
		else if(ganha(b, a) && ganha(b, c))
			puts("Iron Maiden's gonna get you, no matter how far!");
		else if(ganha(c, a) && ganha(c, b))
			puts("Urano perdeu algo muito precioso...");
		else
			puts("Putz vei, o Leo ta demorando muito pra jogar...");

	}
	return 0;
}