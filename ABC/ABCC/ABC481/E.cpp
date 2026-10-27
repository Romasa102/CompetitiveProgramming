#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

struct point {
    int x, y;
};
long long cross(const point &a, const point &b) {
    return (long long) a.x * b.y - (long long) a.y * b.x;
}
bool cmp(const point &a, const point &b) {
    int ah = (a.y < 0 or (a.y == 0 and a.x < 0));
    int bh = (b.y < 0 or (b.y == 0 and b.x < 0));
    if (ah != bh) return ah < bh;
    return cross(a, b) > 0;
}
void argument_sort(vector<point> &points) {
    sort(points.begin(), points.end(), cmp);
}

long long dot(const point &a, const point &b) {
    return (long long)a.x * b.x + (long long)a.y * b.y;
}

bool within180(const point &a, const point &b) {
    long long c = cross(a, b);
    return c > 0 || (c == 0 && dot(a, b) > 0);
}

int main(){
    ll T;
    cin >> T;
    rep(_,T){
        ll N;
        cin >> N;
        vector<point> pt(N);
        rep(i,N)cin >> pt[i].x >> pt[i].y;
        vector<int> ord(N);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j){ return cmp(pt[i], pt[j]); });

        vector<point> rev(2*N);
        rep(i,2*N) rev[i] = pt[ord[i%N]];
        ll ans = 0;
        rep(i,N){
            const point &a = rev[i];
            ll st = lower_bound(rev.begin(), rev.end(), a, cmp) - rev.begin();
            ll lo = st, hi = st + N;
            while (hi - lo > 1) {
                ll mid = (lo + hi) / 2;
                if (within180(a, rev[mid % N])) lo = mid;
                else hi = mid;
            }
            ll last = lo;
            ll cnt  = last - st + 1;
            ans = max(cnt,ans);
        }
        cout << ans << endl;
    }
}