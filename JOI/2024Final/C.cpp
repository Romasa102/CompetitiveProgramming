#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,L;
    cin >> N >> L;
    vector<ll> X(N);
    rep(i,N)cin >> X[i];
    ll Q;cin >> Q;
    ll S[Q],G[Q],T[Q];
    rep(i,Q)cin >> S[i] >> G[i] >> T[i];
    sort(X.begin(),X.end());
    ll ans = X[N-1];
    ll cur = 2;
    for(ll i = N-1; i>=1; i--){
        ans += cur * (X[i]-X[i-1]);
        cur++;ans++;
    }
    ans += cur * X[0];
    rep(i,Q){
        if(T[i]>ans)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}