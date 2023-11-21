#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> lazy;
vector<ll> node;
ll n=1;
int const INF = INT_MAX;

void eval(ll x,ll l,ll r){
    if(lazy[x]!=0){
        node[x]+=lazy[x];
        if(r-l>1){
            lazy[2*x+1] += lazy[x];
            lazy[2*x+2] += lazy[x];
        }
        lazy[x]=0;
    }
    return;
}
void add(ll a,ll b,ll x,ll k=0,ll l=0,ll r=n){
    eval(k,l,r);
    if(b<=l||r<=a)return;
    if(a<=l&&r<=b){
        lazy[k]+=x;
        eval(k,l,r);
    }else{
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
        node[k]=min(node[2*k+1],node[2*k+2]);
    }
}
int getmin(int a, int b, int k=0, int l=0, int r=-1) {
    if(r < 0) r = n;
    if(r <= a || b <= l) return INF;
    if(a <= l && r <= b) return node[k];
    eval(k,l,r);
    int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
    int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
    return min(vl, vr);
}
int main(){
    ll n_,q;
    cin >> n_ >> q;
    while(n_>n)n*=2;
    node.resize(n*2-1,0);
    lazy.resize(n*2-1,0);
    rep(i,q){
        ll que;
        cin >> que;
        if(que == 0){
            ll s,t,x;
            cin >> s >>t >> x;
            add(s,t,x);
        }else{
            ll s,t;
            cin >> s >> t;
            cout << getmin(s,t+1) << endl;
        }
    }
}