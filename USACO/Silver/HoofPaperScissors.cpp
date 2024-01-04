#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    ll N;
    cin >> N;
    char Ges[N];
    rep(i,N)cin >> Ges[i];
    vector<ll> p(N+1,0),h(N+1,0),s(N+1,0);
    rep(i,N){
        if(Ges[i]=='P'){
            p[i+1]=p[i]+1;
            h[i+1]=h[i];
            s[i+1]=s[i];
        }else if(Ges[i]=='H'){
            p[i+1]=p[i];
            h[i+1]=h[i]+1;
            s[i+1]=s[i];
        }else if(Ges[i]=='S'){
            p[i+1]=p[i];
            h[i+1]=h[i];
            s[i+1]=s[i]+1;
        }
    }
    ll ans =0;
    rep(i,N){
        ans = max({ans,p[i]+s[N]-s[i],p[i]+h[N]-h[i],s[i]+h[N]-h[i],s[i]+p[N]-p[i],h[i]+p[N]-p[i],h[i]+s[N]-s[i]});
    }
    cout << ans << endl;
}