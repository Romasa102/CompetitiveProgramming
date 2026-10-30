#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
vector<vector<ll>> jmp;
ll LOG;
int main(){
    ll N;
    cin >> N;
    ll x[N-1],y[N-1];
    rep(i,N-1)cin >> x[i] >> y[i];
    ll Q;cin >> Q;
    ll Nc=N;
    while(Nc>0){
        Nc/=2;
        LOG++;
    }
    jmp.resize(N,vector<ll>(LOG,0));
    rep(i,N){
        rep(j,LOG){
            jmp[i][j] = jmp[i]
        }
    }

}