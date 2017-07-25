class ConvexHullTrick {
    struct CHTPoint {
        ld x, y;
        int idx;
        ld lim;
    };
    vector<CHTPoint> pilha;
    inline ld get_intersection(CHTPoint a, CHTPoint b) {
        ld denom = ( ld(b.x) - a.x);
        ld num = ( ld(b.y) - a.y);
 
        return - num / denom;
    }
 
    bool ccw(CHTPoint p0, CHTPoint p1, CHTPoint p2) {
        return ((ld)(p1.y-p0.y)*(ld)(p2.x-p0.x) > (ld)(p2.y-p0.y)*(ld)(p1.x-p0.x));
    }
 
    public:
 
    void add_line(ld a, ld b, int idx) {
        CHTPoint novo = {a, b, idx, 0};
        int tam = pilha.size();
        while (tam >= 2 && !ccw(pilha[tam-2], pilha[tam-1], novo)) {
            pilha.pop_back();
            tam--;
        }
        while (tam >= 1 && fabs(pilha[tam-1].x - a) < 1e-8) {
            pilha.pop_back();
            tam--;
        }
 
        pilha.push_back(novo);
        if (tam >= 1) pilha[tam-1].lim = get_intersection(pilha[tam-1], pilha[tam]);
    }
 
    pair<int, ld> get_maximum(ld x) {
        int st = 0, ed = pilha.size() - 1;
        while (st < ed) {
            int mid = (st+ed)/2;
            if (pilha[mid].lim < x) st = mid+1;
            else ed = mid;
        }
        return make_pair(pilha[st].idx, pilha[st].x * x + pilha[st].y);
    }
 
    void print() {
        // for (int i = 0; i < pilha.size(); i++) {
        //     printf("%f %f %f\n", pilha[i].x, pilha[i].y, pilha[i].lim);
        // }
    }
};
c