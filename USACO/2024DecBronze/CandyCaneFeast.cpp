#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll cow[N],can[M];
    rep(i,N){
        cin >> cow[i];
    }
    rep(i,M){
        cin >> can[i];
    }
    rep(i,M){
        ll cur = 0;
        rep(j,N){//cow
            if(cur < cow[j]){
                ll cash = cow[j];
                cow[j]+=min(cow[j],can[i])-cur;
                cur = min(cash,can[i]);
            }
        }
    }
    rep(i,N){
        cout << cow[i] << endl;
    }
}