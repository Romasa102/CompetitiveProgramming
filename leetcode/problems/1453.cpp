#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> a(n,vector<ll>(2));
    rep(i,n)cin >> a[i][0] >> a[i][1];
    ll r = 0;
    cin >> r;
    solve(a,r);
}


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
typedef Point<double> P;

bool circleInter(P a,P b,double r1,double r2,pair<P, P>* out) {
    if (a == b) { assert(r1 != r2); return false; }
    P vec = b - a;
    double d2 = vec.dist2(), sum = r1+r2, dif = r1-r2,
        p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
    if (sum*sum < d2 || dif*dif > d2) return false;
    P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
    *out = {mid + per, mid - per};
    return true;
}

int solve(vector<vector<ll>> darts, ll r){
    int n = darts.size();
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            P a = P(darts[i][0],darts[i][1]);
            P b = P(darts[j][0],darts[j][1]);

            //check the dist between points
            if((a-b).dist() > r)continue;

            // at this point it is guranteed that these two point can be at the edge of the circle.
            // to get the center point of the circle we have to get the perpendicular line to the line between these points
            // and then make a perpendicular line and measure the dist.
            // sqrt(r^2-(dist/2)^2) is the displacement
            // get the angle between two points. when y = ax perpendicular line is y = -1/a x

            // line operation too complicated. We can make circle from both point with rad = r and get intersection.

            pair<P,P> out;
            circleInter(a,b,r,r,&out);
            int cnt = 0;
            for(int k = 0; k < n; k++){
                P c = P(darts[k][0],darts[k][1]);
                if((c-a).dist() <= r){
                    cnt++;
                }
            }
            cout << cnt << endl;
            ans = max(ans,cnt);
        }
    }
    return ans;
}
