#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll t;
    cin >> t;
    rep(_,t){
        ll n;cin >> n;
        ll b[n];
        rep(i,n)cin >> b[i];

        bool fail = false;
        vector<ll> ans(n,-1);
        rep(i,n){
            ll idx = n-1+b[i]-i;
            if(idx<0 || idx>=n){ fail=true; continue; }
            ans[idx]=i+1;
        }
        rep(i,n){
            if(ans[i]==-1)fail=true;
        }
        if(fail){
            cout << -1 << endl;
            continue;
        }
        rep(i,n){
            cout << ans[i] << " ";
        }cout << endl;
    }
}