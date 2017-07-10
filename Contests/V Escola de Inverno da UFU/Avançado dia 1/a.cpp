/*input
())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10
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

#define MAXN 1000001

struct node{
    int ans, open, close;
};

char s[MAXN];

node operator+(node foo, node bar){
    node res;

    int consegue = min(foo.open, bar.close);
    res.ans = foo.ans + bar.ans + consegue;
    res.open = foo.open + bar.open - consegue;
    res.close = foo.close + bar.close - consegue;

    return res;
}

node tree[4*MAXN];

void build(int idx, int l, int r){
    if(l == r){
        tree[idx].open = tree[idx].close = tree[idx].ans = 0;
        if(s[l] == '(')
            tree[idx].open = 1;
        else
            tree[idx].close = 1;
        return;
    }
    build(idx*2, l, (l+r)/2);
    build(idx*2+1, (l+r)/2+1, r);
    tree[idx] = tree[idx*2] + tree[idx*2+1];
}
node null(){
    node ans;
    ans.open = ans.close = ans.ans = 0;
    return ans;
}
node get(int idx, int l, int r, int i, int j){
    if(l > j || r < i)
        return null();
    if(l >= i && r <= j)
        return tree[idx];
    return get(idx*2, l, (l+r)/2, i, j) + get(idx*2+1, (l+r)/2+1, r, i, j);
}


int main(){
	//freopen("in.c", "rt", stdin);
    scanf("%s", s);
    int n = strlen(s);
    build(1, 0, n-1);

    int q, l, r;
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &l, &r);
        l--, r--;
        printf("%d\n", 2*get(1, 0, n-1, l, r).ans);
    }

	return 0;
}