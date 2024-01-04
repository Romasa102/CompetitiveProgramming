#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);
    ll N,Q;
    cin >> N >> Q;
    ll id[N];
    rep(i,N)cin >> id[i];
    vector<ll> a(N+1,0),b(N+1,0),c(N+1,0);
    a[0]=0;b[0]=0;c[0]=0;
    rep(i,N){
        if(id[i]==1){
            a[i+1]=a[i]+1;
            b[i+1]=b[i];
            c[i+1]=c[i];
        }else if(id[i]==2){
            b[i+1]=b[i]+1;
            a[i+1]=a[i];
            c[i+1]=c[i];
        }else if(id[i]==3){
            c[i+1]=c[i]+1;
            b[i+1]=b[i];
            a[i+1]=a[i];
        }
    }
    rep(i,Q){
        ll l,r;
        cin >> l >> r;
        cout << a[r]-a[l-1] << " " << b[r]-b[l-1] << " " << c[r]-c[l-1] << endl;
    }
}