#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

struct BIT {
    int n;
    vector<ll> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void add(int i, ll v) {
        for (i++; i <= n; i += i & -i) t[i] += v;
    }
    ll sum(int i) {
        ll s = 0;
        for (; i > 0; i -= i & -i) s += t[i];
        return s;
    }
    ll query(int l, int r) {
        return sum(r + 1) - sum(l);
    }
};


int main(){
    ll t;
    cin >> t;
    rep(_,t){
        ll n,m;cin >> n >> m;
        ll l[m],r[m];
        rep(i,m){
            cin >> l[i] >> r[i];
            l[i]--;
            r[i]--;
        }
        ll q;
        cin >> q; 
        ll x[q];
        rep(i,q){
            cin >> x[i];
            x[i]--;
        }
        ll left = 0;
        ll right = q;
        ll ans = -2;
        while(right - left > 1){ // left include, right not include.
            ll mid = (left + right)/2;
            bool condition = false;
            BIT bitT(n);
            rep(i,mid+1){
                bitT.add(x[i],1);
                //add to segment tree
            }
            rep(i,m){
                //cout << "target sum is " << (r[i]-l[i]+3)/2 << " actual sum is " << bitT.query(l[i],r[i]) << endl;
                if((r[i]-l[i]+3)/2 <= bitT.query(l[i],r[i])){
                    condition = true;
                    break;
                }
                //check each range with segment tree range sum query
            }
            if(condition){
                left = mid;
                ans = left;
            }else{
                right = mid;
            }
        }
        cout << ans + 1 << endl;
    }

}