#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	rep(i,v.size()-1) a += v[i].cross(v[i+1]);
	return a;
}


ll gcd(ll a,ll b){
    if(a == 0)return b;
    if(b == 0)return a;
    if(a==1)return a;
    if(b==1)return b;
    if(a==b)return a;
    if(a>b)swap(a,b);
    return gcd(a,b-a);
}

int main(){
    ll n;
    cin >> n;
    vector<Point<ll>> points(n);
    rep(i,n)cin >> points[i].x >> points[i].y;
    ll edgeC = 0;
    rep(i,n){
        ll num = (i+1)%n;
        //cout << num <<" :" << points[num].x << points[num].y << endl;
        //cout << i <<" :" << points[i].x << points[i].y << endl;
        ll val1 = abs(points[num].x - points[i].x);
        ll val2 = abs(points[num].y - points[i].y);
        //cout <<"get gcd of " << val1 << val2 << endl;
        edgeC += gcd(val1, val2);
        //cout << gcd(val1,val2) << " was added as edge " << endl;
    }
    ll area = llabs(polygonArea2(points)/2);
    //A = i + b/2 - 1
    //i = A-b/2+1
    cout << area - edgeC/2 + 1 <<" "<< edgeC << endl;
}