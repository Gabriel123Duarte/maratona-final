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
int freq[MAXN], total[MAXN];
int resp;
void add(int id){
    if(!vis[id]){
        total[freq[v[id]]]--;
        if(freq[v[id]] == resp)
            resp++;

        freq[v[id]]++;
        total[freq[v[id]]]++;
    }
    else{
        total[freq[v[id]]]--;
        if(freq[v[id]] == resp && !total[freq[v[id]]])
            resp--;

        freq[v[id]]--;
        total[freq[v[id]]]++;
    }

    vis[id] ^= 1;
}

int main(){
	//freopen("in.c", "rt", stdin);
    while(scanf("%d", &n), n){
        scanf("%d", &q);
        mp.clear();
        for(int i = 0; i < n; i++){
            scanf("%d", v+i);
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
            scanf("%d %d", &queries[i].l, &queries[i].r);
            queries[i].l--;
            queries[i].r--;
            queries[i].id = i;
        }

        sort(queries, queries+q);
        int ans[q];
        int curL = 0, curR = 0;
        memset(vis, 0, sizeof vis);
        memset(freq, 0, sizeof freq);
        memset(total, 0, sizeof total);
        resp = 0;
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
            ans[queries[i].id] = resp;
        }

        for(int i = 0; i < q; i++)
            printf("%d\n", ans[i]);

    }
	return 0;
}
