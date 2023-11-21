#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll parent[9];
ll find(ll x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}
int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    map<P,ll> uv;
    pair<P,ll> uvs[M];
    rep(i,M){
        ll u,v,w;
        cin >> u >> v >> w;
        uvs[i].first={u-1,v-1};
        uvs[i].second = w;
    }
    vector<ll> nums;
    rep(i,N)parent[i] = i;
    ll Fans = 1LL<<50;
    for(ll bit = 0; bit < 1LL<<M; bit++){
        if(__builtin_popcount(bit)!=N-1)continue;
        bool work = true;
        ll ans = 0;
        rep(i,N)parent[i] = i;
        rep(i,M){
            if((1LL<<i)&bit){
                ans+=uvs[i].second;
                ans%=K;
                if(find(uvs[i].first.first) == find(uvs[i].first.second)){
                    work = false;
                    break;
                }
                parent[find(uvs[i].first.first)] = find(uvs[i].first.second);
            }
        }
        ll ev = find(0);
        repp(i,1,N){
            if(find(i)!=ev)work=false;
        }
        if(work){
            Fans = min(ans%K,Fans);
        }
    }
    cout << Fans << endl;

}