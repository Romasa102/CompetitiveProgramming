#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll seg[1000100];
ll n,q;
void init(int n_){
    n=1;
    while(n<n_)n*=2;
}
void updateN(ll k,ll a){
    k+=n-1;
    seg[k] = a;
    while(k>0){
        k = (k-1)/2;
        seg[k] = min(seg[2*k+1],seg[2*k+2]);
    }
}
ll que(ll a,ll b,ll k,ll l, ll r){
    if(r<=a || b<=l){
        return 1LL<<32;
    }
    if(a<=l && r<=b){
        return seg[k];
    }else{
        ll v1 = que(a,b,k*2+1,l,(l+r)/2);
        ll v2 = que(a,b,k*2+2,(l+r)/2,r);
        return min(v1,v2);
    }
}
int main(){
    ll po;
    cin >> po >> q;
    init(po);
    rep(i,1000000){
        seg[i] = (1LL<<31)-1;
    }
    rep(i,q){
        ll quer;
        cin >> quer;
        ll a,b;
        cin >> a >> b;
        if(quer == 0){
            updateN(a,b);
        }else{
            cout << que(a,b+1,0,0,n) << endl;
        }
    }
}