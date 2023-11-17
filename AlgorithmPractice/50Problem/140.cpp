#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> segT;
ll find(ll a,ll b,ll k,ll l,ll r){
    if(a<=l&&b<=r)return segT[k];
    if(r<=a||l<=b)return 1LL<<32;
    ll v1 = find(a,b,2*k+1,l,(l+r)/2);
    ll v2 = find(a,b,2*k+2,(l+r)/2,r);
    return min(v1,v2);
}
void update(ll x,ll a){
    segT[x]=a;
    while(x>0){
        x=(x-1)/2;
        segT[x]=min(segT[2*x+1],segT[2*x+2]);
    }
}
int main(){
    ll n,x;
    cin >> n >> x;
    ll N=1;
    while(N<n)N*=2;
    segT.resize(2*N-1,1LL<<32);
    ll a[N];
    rep(i,N){
        cin >> a[i];
        update(N-1+i,a[i]);
    }
    ll ansF = 1LL<<60;
    rep(i,N){
        ll ans = 0;
        rep(j,N){
            
        }
    }
}