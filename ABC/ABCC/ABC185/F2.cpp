#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> segT;
ll segTS = 1;
void update(ll x,ll y){
    ll cur = segTS/2 + x;
    segT[segTS/2 + x] ^= y;

    while(cur > 1){
        cur/=2;
        segT[cur] = segT[cur*2] ^ segT[cur*2+1];
    }
}

ll query(ll l,ll r,ll curL = 0,ll curR = segTS/2-1, ll ind = 1){
    if(l > curR || r < curL)return 0;
    if(l <= curL && curR <= r){
        return segT[ind];
    }
    return query(l,r,curL,(curL+curR)/2,ind*2) ^ query(l,r,(curL+curR)/2+1,curR,ind*2+1);
}
int main(){
    ll N,Q;cin >> N >> Q;
    while(segTS < N)segTS*=2;
    segTS*=2;
    segT.resize(segTS,0);
    ll A[N];
    rep(i,N){
        cin>>A[i];
        update(i,A[i]);
    }
    rep(_,Q){
        ll t,x,y;
        cin >> t >> x >> y;
        if(t == 1){
            x--;
            update(x,y);
        }else{
            x--;y--;
            cout << query(x,y) << endl;
        }
    }
}