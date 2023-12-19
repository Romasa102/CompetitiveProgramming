#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("milkorder.in","r",stdin);
    ll N,M,K;
    cin >> N >> M >> K;
    ll m[M],c[K],p[K];
    rep(i,M)cin >> m[i];
    rep(i,K)cin >> c[i] >> p[i];
    vector<bool> LockPos(M,false);//place that is already locked
    vector<ll> pos(N,-1);//current state
    rep(i,K){
        pos[p[i]-1]=c[i];
        rep(j,M){
            if(c[i]==m[j]){
                LockPos[j]=true;
            }
        }
    }
    vector<ll> counter;
    vector<vector<ll>> rollBack(M);
    rep(i,M){
        if(!LockPos[i]){
            counter.push_back(m[i]);
        }else{
            rollBack[i]=counter;
            counter.clear();
        }
    }
    rep(i,K){
        rep(j,M){
            if(c[i]==m[j]){
                if(rollBack[j].size()!=0){
                    ll count = rollBack[j].size();
                    for(ll k = p[i]-2; k >= 0; k--){
                        if(count==0)break;
                        if(pos[k]==-1){
                            pos[k]=m[count-1];
                            count--;
                        }
                    }
                }
            }
        }
    }
    freopen("milkorder.out","w",stdout);
    rep(i,N){
        if(pos[i]==1){
            cout << i+1 << endl;
            return 0;
        }
    }
    rep(i,N){
        if(pos[i]==-1){
            cout << i+1 << endl;
            return 0;
        }
    }
}