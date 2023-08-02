#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll k;
    ll p[M];
    vector<vector<ll>> Swi(M);
    rep(i,M){
        cin >> k;
        rep(j,k){
            ll o;
            cin >> o;
            Swi[i].push_back(o); 
        }
    }
    rep(i,M){
        cin >> p[i];
    }
    for(int bit = 0;bit < 1<<N; bit++){
        for(int i = 0; i < N; i++){
            if(bit & 1<<i){
                
            }
        }
    }
}