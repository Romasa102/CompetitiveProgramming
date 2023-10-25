#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,vector<ll>> connection;
map<ll,vector<ll>> Rconnection;
ll N,M;
bool searched[110000];
ll group[110000];
vector<ll> vs;
ll cur =0;
ll dfs(ll a){
    searched[a]=true;
    for(ll i:connection[a]){
        if(!searched[i]){
            dfs(i);
        }
    }
    vs.push_back(a);
    return 0;
}
ll Rdfs(ll b){
    group[b]=cur;
    searched[b]=true;
    ll GROUP=1;
    for(ll i:Rconnection[b]){
        if(!searched[i]){
            GROUP+=Rdfs(i);
        }
    }
    return GROUP;
}
int main(){
    cin >> N >> M;
    ll A[M],B[M];
    rep(i,M){
        cin >> A[i] >> B[i];
        A[i]--;B[i]--;
        connection[A[i]].push_back(B[i]);
        Rconnection[B[i]].push_back(A[i]);
    }
    rep(i,N){
        if(!searched[i]){
            dfs(i);
        }
    }
    memset(searched,0,sizeof (searched));
    ll ans = 0;
    std::reverse(vs.begin(), vs.end());
    for(ll i:vs){
        if(!searched[i]){
            ll o = Rdfs(i);
            //ans += oC2
            if(o!=1){
                ans += o*(o-1)/2;
            }
            cur++;
        }
    }
    cout << ans << endl;
}