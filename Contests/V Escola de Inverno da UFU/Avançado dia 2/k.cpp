/*input
9 4
2 3 4 5 6 7 4 9 5
1 3
3 5
2 8
7 9

9 4
2 3 4 5 6 7 4 9 5
1 3
3 5
2 8
7 9
3 3
1 3 3
1 1
1 2
2 3
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

#define MAXN 50010
#define BLOCK 225 
#define INF 0x3f3f3f3f

inline int cmp(double x, double y = 0, double tol = 1e-7)
{ return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

int menorPos[MAXN], go[MAXN], visitados[MAXN];
int bit[MAXN];
int menor;

void dfs(int u){
	if(menorPos[u] != INF){
		menor = min(menorPos[u], menor);
		return;
	}
	visitados[u] = 1;
	menor = min(menor, u);
	if(!visitados[go[u]])
		dfs(go[u]);
}

void update(int x, int val){
	for(; x < MAXN; x +=x&-x)
		bit[x] += val;
}

int query(int x){
	int sum = 0;
	for(; x; x -= x&-x)
		sum += bit[x];
	return sum;
}

struct consulta{
	int l, r, id;	
};

bool comparar(consulta a, consulta b){
	if(a.l / BLOCK != b.l / BLOCK)
		return a.l / BLOCK < b.l / BLOCK;
	return a.r < b.r;
}

void add(int id){
	update(menorPos[id], 1);
}

void remove(int id){
	update(menorPos[id], -1);
}

template<class num>inline void rd(num &x)
{
    char c;
    while(isspace(c = getchar()));
    bool neg = false;
    if(!isdigit(c))
        neg=(c=='-'), x=0;
    else
        x=c-'0';
    while(isdigit(c=getchar()))
        x=(x<<3)+(x<<1)+c-'0';
    if(neg)
        x=-x;
}


int main(){
	int n, q;
	rd(n);
	rd(q);
	for(int i = 0; i < n; i++){
		rd(go[i]);
		go[i]--;
		if(go[i] == i)
			menorPos[i] = i;
		else
			menorPos[i] = INF;
		visitados[i] = bit[i] = 0;
	}


	for(int i = 0; i < n; i++){
		memset(visitados, 0, sizeof visitados);
		menor = i;
		dfs(i);
		menorPos[i] = menor;
	}

	for(int i = 0; i < n; i++)
		menorPos[i]++;

	consulta consultas[q];
	for(int i = 0; i < q; i++){
		rd(consultas[i].l);
		rd(consultas[i].r);
		consultas[i].id = i;
		consultas[i].l--;
		consultas[i].r--;
	}

	sort(consultas, consultas + q, comparar);
	int ansConsultas[q];
	int curL = 0, curR = 0;

	for(int i = 0; i < q; i++){	
		int L = consultas[i].l, R = consultas[i].r;
		int totalCaras = (R - L + 1);
		
		while(curL < L){
			remove(curL);
			curL++;
		}
		while(curL > L){
			add(curL - 1);
			curL--;
		}
		while(curR <= R){
			add(curR);
			curR++;
		}
		while(curR > R + 1){
			remove(curR - 1);
			curR--;
		}
		
		int bl = 1, br = n, ans = 0;
		double aux = 0;
		while(bl <= br){
			int mid = (bl + br) / 2;
			int totalMenor = query(mid);
			double pAtual = (double)(totalMenor * 100.00) / totalCaras;
			
			if(cmp(pAtual, 50.00) == 1){
				if(cmp(pAtual - 50.00, fabs(aux - 50.00)) == -1){
					aux = pAtual;
					ans = mid;
				}
				br = mid - 1;
			}
			else if(cmp(pAtual, 50.00) == -1){
				if(cmp(50.00 - pAtual, fabs(50.00 - aux)) == -1){
					aux = pAtual;
					ans = mid;
				}
				bl = mid + 1;
			}
			else{
				ans = mid;
				aux = 50.00;
				break;
			}

		}

		bool mudei = true;
		for(mudei = false; ans >= 1; ans--){				
			if(cmp(fabs((((double)query(ans) * 100) / totalCaras) - 50.0), fabs(aux - 50.0)) != 0)
				break;				
			mudei = true;
		}
		if(mudei){
			ans++;
			aux = (query(ans) * 100) / (double)totalCaras;
		}
		

		ansConsultas[consultas[i].id] = max(1, ans);
	}

	for(int i = 0; i < q; i++)
		printf("%d\n", ansConsultas[i]);

	return 0;
}