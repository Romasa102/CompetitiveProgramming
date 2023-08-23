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
    rep(i,N){
        cin >> a[i] >> b[i] >> c[i];
        change[a[i]] += c[i];
        change[b[i]+1] -= c[i];
    }
    ll ans = 0;
    ll prev = 0;
    repp(i,1,10000001){
        if(change.find(i) != change.end()){
            prev = prev + change[i];
        }
        if(prev > C){
            ans += C;
        }else{
            ans += prev;
        }
    }
    cout << ans << endl;
}