#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll X[N],Y[N];
    rep(i,N)cin >> X[i] >>  Y[i];
    rep(i,N){
        ll ans = 0;
        ll minA = 0;
        rep(j,N){
            if(i==j)continue;
            ll x1 = abs(X[j]-X[i]);
            ll y1 = abs(Y[j]-Y[i]);
            if(minA < x1*x1+y1*y1){
                ans = j;
            }
            minA = max(minA,x1*x1+y1*y1);
        }
        cout << ans + 1 << endl;
    }
}