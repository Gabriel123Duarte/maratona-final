
#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin (), x.end ()
#define sz(x) (int) x.size ()
#define pb push_back
#define mk make_pair
#define clr clear ()
#define inf (1 << 30)
#define fi first
#define se second
#define pi 2 * acos (0)
#define LSONE(s) ((s) & (-s))
#define mem(x, val) memset ((x), (val), sizeof (x))
#define rep(i, n) for (auto i = 0; i < n; i++)

typedef long long int ll;
typedef unsigned long long int ull;
typedef string st;
typedef vector <string> vs;
typedef vector <int> vi;
typedef map <int, int> mii;
typedef pair <int, int> ii;
typedef pair <int, pair <int, int> > iii;

#define _inline(f...) f() __attribute__((always_inline)); f
const int INF = 10000000;
const double EPS = 1e-9;

_inline(int cmp)(double x, double y = 0, double tol = EPS)
{
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
struct point
{
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    point operator +(point q)
    {
        return point(x + q.x, y + q.y);
    }
    point operator -(point q)
    {
        return point(x - q.x, y - q.y);
    }
    point operator *(double t)
    {
        return point(x * t, y * t);
    }
    point operator /(double t)
    {
        return point(x / t, y / t);
    }
    double operator *(point q)
    {
        return x * q.x + y * q.y;
    }
    double operator %(point q)
    {
        return x * q.y - y * q.x;
    }
    int cmp(point q) const
    {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
    bool operator ==(point q) const
    {
        return cmp(q) == 0;
    }
    bool operator !=(point q) const
    {
        return cmp(q) != 0;
    }
    bool operator < (point q) const
    {
        return cmp(q) < 0;
    }
    friend ostream& operator <<(ostream& o, point p)
    {
        return o << "(" << p.x << ", " << p.y << ")";
    }
    static point pivot;
};
point point::pivot;
double abs(point p)
{
    return hypot(p.x, p.y);
}
double arg(point p)
{
    return atan2(p.y, p.x);
}
typedef vector<point> polygon;
typedef pair<point, double> circle;

bool in_circle(circle C, point p)
{
    return cmp(abs(p - C.first), C.second) <= 0;
}

//////////////////////////////////////////////////////
// Encontra o ponto do segmento mais proximo a C
point circle_closest_point_seg(point p, point q, circle c)
{
    point A = q - p, B = c.first - p;
    double proj = (A * B)/abs(A);
    if (cmp(proj) < 0) return p;
    if (cmp(proj, abs(A)) > 0) return q;
    return p + (A * proj)/abs(A);
}
//////////////////////////////////////////////////////
// Decide se o segmento pq se interseca com c
bool seg_circle_intersect(point p, point q, circle c)
{
    point r = circle_closest_point_seg(p, q, c);
    return in_circle(c, r);
}

struct magia
{
	int d;
	int v[3];
	magia () {};
	magia (int dd, int x1, int x2, int x3)
	{
		d = dd;
		v[0] = x1;
		v[1] = x2;
		v[2] = x3;
	}
};

map <string, magia> mapa;

void gen ()
{
	mapa.insert (make_pair ("fire", magia (200, 20, 30, 50)));
	mapa.insert (make_pair ("water", magia (300, 10, 25, 40)));
	mapa.insert (make_pair ("earth", magia (400, 25, 55, 70)));
	mapa.insert (make_pair ("air", magia (100, 18, 38, 60)));
}

ll sq(ll x){
	return x*x;
}

bool ok(point a, circle c){
	return sq(a.x-c.first.x)+ sq(a.y-c.first.y) <= sq(c.second);
}


int main ()
{
	gen ();
	int t, w, h, x0, y0, cx, lvl, cy;
	st type;
	double X;
	gen ();
	cin >> t;
	while (t--)
	{
		polygon T;
		cin >> w >> h >> x0 >> y0;
		T.pb (point (x0, y0));
		T.pb (point (x0+w, y0));
		T.pb (point (x0+w, y0+h));
		T.pb (point (x0, y0+h));
		cin >> type >> lvl >> cx >> cy;
		circle C (point (cx, cy), mapa[type].v[lvl - 1]);

		bool ans = 1;
		ans &= ok(T[0], C);
		ans &= ok(T[1], C);
		ans &= ok(T[2], C);
		ans &= ok(T[3], C);
		bool ans2 = 0;

		double miniX = 1<<30, miniY= 1<<30;
		double maxiX = -1<<30, maxiY = -1<<30;
		for(int i = 0; i < 4; i++){
			miniX = min(miniX, T[i].x);
			maxiX = max(maxiX, T[i].x);


			miniY = min(miniY, T[i].y);
			maxiY = max(maxiY, T[i].y);
		}

		if(cx >= miniX && cx <= maxiX && cy >= miniY && cy <= maxiY)
			ans2 = 1;
		if (ans2 or ans or seg_circle_intersect (T[0], T[1], C) or seg_circle_intersect (T[1], T[2], C) or seg_circle_intersect (T[2], T[3], C) or seg_circle_intersect (T[3], T[0], C))
			cout << mapa[type].d << endl;
		else
			cout << 0 << endl;
	}
    return 0;
}
