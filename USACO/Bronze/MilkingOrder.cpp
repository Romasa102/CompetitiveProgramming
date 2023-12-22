#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll N,M,K;
bool check(vector<ll> pos,vector<ll> hierarchy){
    vector<ll> cowToPos(N);
    rep(i,pos.size()){
        if(pos[i]!=-1){
            cowToPos[pos[i]]=i;
        }
    }
    rep(i,N){

    }
}
int main(){
    cin >> N >> M >> K;
    vector<ll> m(M),c(K),p(K);
    rep(i,M){
        cin >> m[i];
        m[i]--;
    }
    rep(i,K)cin >> c[i] >> p[i];
    vector<ll> pos(N,-1);
    rep(i,K){
        pos[p[i]-1]=c[i]-1;
    }
    rep(i,N){
        vector<ll> cash = pos;
        if(pos[i]==-1){
            pos[i]=0;
            if(check(cash,m)){
                cout << i+1 << endl;
                return 0;
            }
        }
    }
}