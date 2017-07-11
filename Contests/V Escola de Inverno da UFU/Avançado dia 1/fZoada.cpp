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
int BLOCK;

struct query{
    int l, r, id;
    bool operator<(const query foo)const{
        if(l / BLOCK != foo.l / BLOCK)
            return l / BLOCK < foo.l / BLOCK;
        return r < foo.r;
    }
};

int v[MAXN];
unordered_map<int, int> mp;
int vis[MAXN];
int n, q;
int tree[4*MAXN];

void update(int idx, int l, int r, int i, int v){
    if(l > i || r < i)
        return;
    if(l == r && l == i){
        tree[idx] += v;
        return;
    }
    update(idx*2, l, (l+r)/2, i, v);
    update(idx*2+1, (l+r)/2+1, r, i, v);
    tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

int get(int idx, int l, int r, int x, int y){
    if(l > y || r < x)
        return 0;
    if(l >= x && r <= y)
        return tree[idx];
    return max(get(idx*2, l, (l+r)/2, x, y), get(idx*2+1, (l+r)/2+1, r, x, y));
}

void add(int id){
    if(!vis[id])
        update(1, 0, n-1, v[id], 1);
    else
        update(1, 0, n-1, v[id], -1);

    vis[id] ^= 1;
}

int main(){
	//freopen("in.c", "rt", stdin);
    while(scanf("%d", &n), n){
        scanf("%d", &q);
        mp.clear();
        for(int i = 0; i < n; i++){
            rd(v[i]);
            mp[v[i]] = 1;
        }

        int id = 0;
        for(auto it = mp.begin(); it != mp.end(); it++)
            mp[it->fst] = id++;

        for(int i = 0; i < n; i++)
            v[i] = mp[v[i]];

        BLOCK = sqrt(n);
        query queries[q];
        for(int i = 0; i < q; i++){
            //scanf("%d %d", &queries[i].l, &queries[i].r);
            rd(queries[i].l);
            rd(queries[i].r);
            queries[i].l--;
            queries[i].r--;
            queries[i].id = i;
        }

        sort(queries, queries+q);
        int ans[q];
        int curL = 0, curR = 0;
        memset(vis, 0, sizeof vis);
        memset(tree, 0, sizeof tree);

        for(int i = 0; i < q; i++){
            int l = queries[i].l, r = queries[i].r;

            while(curL < l)
                add(curL++);
            while(curL > l)
                add(--curL);
            while(curR <= r)
                add(curR++);
            while(curR > r + 1)
                add(--curR);
            ans[queries[i].id] = get(1, 0, n-1, 0, n-1);
        }

        for(int i = 0; i < q; i++)
            printf("%d\n", ans[i]);

    }
	return 0;
}
