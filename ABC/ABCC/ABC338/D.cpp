#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;cin >> N >> M;
    ll X[M];
    rep(i,M){
        cin >> X[i];
        X[i]--;
    }
    map<ll,ll> imos;
    vector<ll> roads(N,0);
    ll ans = 0;
    rep(i,M-1){
        ll cur = max(X[i+1],X[i])-min(X[i+1],X[i]);
        if(cur <= N/2){
            ans += cur;
            //(N-cur)-cur = N-2*cur
            imos[min(X[i+1],X[i])]+=(N-(cur*2));
            imos[max(X[i+1],X[i])]-=(N-(cur*2));
        }else{
            ans += (N-cur);
            //cur-(N-cur) = 2*cur-N
            imos[max(X[i+1],X[i])]+=(2*cur-N);
            imos[min(X[i+1],X[i])+N]-=(2*cur-N);
        }
    }
    ll current = 0;
    rep(i,2*N+10){
        if(imos.find(i) != imos.end()){
            current+=imos[i];
        }
        if(current<0)continue;
        if(i >= N){
            roads[i-N]+=current;
        }else{
            roads[i]+=current;
        }
    }
    ll minC = 1LL<<60;
    rep(i,roads.size()){
        minC = min(minC,roads[i]);
    }
    cout << ans + minC << endl;
}