#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll L[N];ll R[N];
    rep(i,N)cin >> L[i] >> R[i];
    map<ll,vector<P>> pos;
    rep(i,N){
        pos[L[i]].push_back(i,0);
        pos[R[i]].push_back(i,1);
    }
    queue<P> LR;
    ll ans = 0;
    ll end = M;
    for (ll i = M-1; i>=0; i--) {
        if(pos[i].empty()){
            ans += (end - i);
            continue;
        }
        rep(j,N){
            pos[i][j].second == 0;
            while(LR.front().first == pos[i][j].first){
                LR.pop();
            }
            LR.push(pos[i][j].first)
        }
        LR.push({pos[i]})
    }
}