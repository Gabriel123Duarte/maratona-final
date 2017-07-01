/*input
pedra pedra pedra
pedra pedra papel
pedra pedra tesoura
pedra papel pedra
pedra papel papel
pedra papel tesoura
pedra tesoura pedra
pedra tesoura papel
pedra tesoura tesoura
papel pedra pedra
papel pedra papel
papel pedra tesoura
papel papel pedra
papel papel papel
papel papel tesoura
papel tesoura pedra
papel tesoura papel
papel tesoura tesoura
tesoura pedra pedra
tesoura pedra papel
tesoura pedra tesoura
tesoura papel pedra
tesoura papel papel
tesoura papel tesoura
tesoura tesoura pedra
tesoura tesoura papel
tesoura tesoura tesoura

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