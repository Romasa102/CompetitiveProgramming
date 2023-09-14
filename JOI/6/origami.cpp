#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll p[n],q[n],r[n],s[n];
    map<P,ll> overLap;
    rep(i,n){
        cin >> p[i] >> q[i] >> r[i] >> s[i];
        repp(j,p[i],r[i]+1){
            repp(k,q[i],s[i]+1){
                if(overLap.find({j,k})==overLap.end()){
                    overLap[{j,k}] = 1;
                }else{
                    overLap[{j,k}]+=1;
                }
            }
        }
    }
    ll size = 0;
    ll ans = 0;
    for (auto itr = overLap.begin(); itr != overLap.end(); itr++) {
        ans = max(ans,itr->second);
    }
    for (auto itr = overLap.begin(); itr != overLap.end(); itr++) {
        if(ans == itr->second){
            size++;
        }
    }
    cout << ans << endl;
    cout << size << endl;
}