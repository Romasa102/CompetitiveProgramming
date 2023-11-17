#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> node;
ll find(ll a,ll b,ll k, ll x, ll y){
    if(a<=x&&y<=b){
        return node[k];
    }
    if(a>=y || b<=x){
        return (1LL<<32)-1;
    }
    ll v1 = find(a,b,2*k+1,x,(x+y)/2);
    ll v2 = find(a,b,2*k+2,(x+y)/2,y);
    return min(v1,v2);
}
int main(){
    ll n_,q;
    cin >> n_ >> q;
    ll n=1;
    while(n<n_){
        n*=2;
    }
    node.resize(2*n-1,(1LL<<31)-1);
    rep(i,q){
        ll s;
        ll x,y;
        cin >> s >> x >> y;
        if(s==0){
            ll nn = n-1+x;
            node[nn]=y;
            while(nn!=0){
                nn=(nn-1)/2;
                node[nn]=min(node[nn*2+1],node[nn*2+2]);
            }
        }else{
            cout << find(x,y+1,0,0,n) << endl;
        }
    }
}