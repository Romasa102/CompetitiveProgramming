#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll W,H,N;
    cin >> W >> H >> N;
    ll c,d;
    cin >> c >> d;
    ll ans = 0;
    rep(i,N-1){
        ll a,b;
        cin >> a >> b;
        ll difx = c-a;
        ll dify = d-b;
        if(difx >0 && dify > 0){
            ans += min(difx,dify);
            ans += max(difx,dify) - min(difx,dify);
        }else if(difx < 0 && dify < 0){
            ans += abs(max(difx,dify));
            ans += abs(min(difx,dify) - max(difx,dify));
        }else{
            ans += abs(difx);
            ans += abs(dify);
        }
        c = a;
        d = b;
    }
    cout << ans << endl;
}