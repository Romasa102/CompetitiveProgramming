#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,C;
    cin >> N >> C;
    ll a[N];
    ll b[N];
    ll c[N];
    map<ll,ll> change;
    vector<P> Change;
    rep(i,N){
        cin >> a[i] >> b[i] >> c[i];
        Change.push_back({a[i],c[i]});
        Change.push_back({b[i]+1,-c[i]});
    }
    ll ans = 0;
    ll prev = 0;
    sort(Change.begin(),Change.end());
    repp(i,1,Change.size()){
        prev = prev + Change[i-1].second;
        if(prev < C){
            ans += prev * (Change[i].first - Change[i-1].first);
        }else{
            ans += C * (Change[i].first - Change[i-1].first);
        }
    }
    cout << ans << endl;
}