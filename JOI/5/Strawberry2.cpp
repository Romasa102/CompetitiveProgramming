#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    P center[9] = {{-1,-1},{-1,0},{0,-1},{0,0},{1,0},{0,1},{1,1},{-1,1},{1,-1}};
    ll H,W,N;
    cin >> H >> W >> N;
    P point[N];
    map<P,ll> existence;
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        point[i] = {a,b};
        existence[{a,b}]++;
    }
    ll ans = 0;
    rep(i,N){
        ll x = point[i].first;
        ll y = point[i].second;
        rep(j,9){
            P centerN = {x + center[j].first,y+center[j].second};
            ll counter = 0;
            rep(k,9){
                if(existence.find({(centerN.first + center[k].first),(centerN.second + center[k].second)})!=existence.end()){
                    counter+=existence[{(centerN.first + center[k].first),(centerN.second + center[k].second)}];
                }
            }
            ans = max(ans,counter);
        }
    }
    cout << ans << endl;
}