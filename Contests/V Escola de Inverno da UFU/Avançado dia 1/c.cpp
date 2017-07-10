#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> ii;

#define MAXN 100100

struct node{
    node *l, *r;
    int val;
    node(){
        l = r = 0;
        val = 0;
    }
};

int v[MAXN];
map<int, int> mp, mp2;
vector<node *> roots;

void build(node *cur, int l, int r){
    if(l == r)
        return;
    cur->l = new node();
    cur->r = new node();
    build(cur->l, l, (l+r)/2);
    build(cur->r, (l+r)/2+1, r);
}

void update(node *last, node *cur, int l, int r, int x){
    if(l > x  || r < x)
        return;
    if(l == r){
        cur->val = last->val + 1;
        return;
    }

    int mid = (l+r)/2;
    if(x <= mid){
        cur->r = last->r;
        cur->l = new node();
        update(last->l, cur->l, l, mid, x);
    }
    else{
        cur->l = last->l;
        cur->r = new node();
        update(last->r, cur->r, mid+1, r, x);
    }

    cur->val = cur->l->val + cur->r->val;
}

int get(node *last, node *cur, int l, int r, int k){
    if(l == r)
        return l;
    int sum = cur->l->val - last->l->val;
    int mid = (l+r)/2;
    if(sum >= k)
        return get(last->l, cur->l, l, mid, k);
    return get(last->r, cur->r, mid+1, r, k-sum);
}


int main(){
	//freopen("in.c", "rt", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", v+i);
        mp[v[i]] = 1;
    }

    int id = 1;
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        mp[it->fst] = id;
        mp2[id++] = it->fst;
    }

    for(int i = 0; i < n; i++)
        v[i] = mp[v[i]];

    roots.pb(new node());
    build(roots.back(), 1, n);
    for(int i = 0; i < n; i++){
        roots.pb(new node());
        update(roots[roots.size()-2], roots.back(), 1, n, v[i]);
    }

    while(m--){
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", mp2[get(roots[l-1], roots[r], 1, n, k)]);
    }
	return 0;
}
