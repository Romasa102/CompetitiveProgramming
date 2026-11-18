#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;


struct Tree {
        typedef ll T;
        static constexpr T unit = 0;
        T f(T a, T b) { return max(a, b); } // (any associative fn)
        vector<T> s; int n;
        Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
        void update(int pos, T val) {
                for (s[pos += n] = val; pos /= 2;)
                        s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
        }
        T query(int b, int e) { // query [b, e)
                T ra = unit, rb = unit;
                for (b += n, e += n; b < e; b /= 2, e /= 2) {
                        if (b % 2) ra = f(ra, s[b++]);
                        if (e % 2) rb = f(s[--e], rb);
                }
                return f(ra, rb);
        }
};

int main(){
    ll N;
    cin >> N;
    ll h[N],a[N];
    ll maxH = 0;
    rep(i,N){
        cin >> h[i];
        maxH = max(maxH,h[i]);
    }
    rep(i,N)cin >> a[i];
    Tree dp(maxH+1);
    ll ans = 0;
    rep(i,N){
        ll maxOld = dp.query(0,h[i]);
        //cout << "query result of height is each ";
        /*rep(i,N){
            cout << dp.query(h[i],h[i]+1) << " ";
        }cout << endl;
        cout << "query result from 0 to" << h[i ] << " is " << maxOld << endl;
        */
        dp.update(h[i], maxOld+a[i]);
        ans = max(ans, maxOld+a[i]);
        //cout << "for the index" << i << " with height of  " << h[i] << " old max was" << maxOld << " and new val is " << maxOld + a[i] << endl;
    }
    cout << ans << endl;
}