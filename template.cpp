#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> ii;

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
	
	return 0;
}