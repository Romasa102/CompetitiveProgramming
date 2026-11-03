#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    vector<ll> R;
    vector<ll> C;
    ll H,W,N,Q;
    cin >> H >> W >> N >> Q;
    rep(i,N){
        ll r,c;
        cin >> r >> c;
        R.push_back(r);
        C.push_back(c);
    }
    sort(R.begin(),R.end());
    sort(C.begin(),C.end());
    rep(_,Q){
        ll task = 0;
        cin >> task;
        ll ans = 0;
        if(task == 2){
            ll u,d;
            cin >> u >> d;
            ans = upper_bound(C.begin(),C.end(),d) - lower_bound(C.begin(),C.end(),u);
        }else{
            ll l,r;
            cin >> l >> r;
            ans = upper_bound(R.begin(),R.end(),r) - lower_bound(R.begin(),R.end(),l);
        }
        cout << ans << endl;
    }
}