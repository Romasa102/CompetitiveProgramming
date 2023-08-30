#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll A[N];
    rep(i,N){
        cin >> A[i];
    }
    ll CumSum[N+1];
    CumSum[0] = 0;
    repp(i,1,N+1){
        CumSum[i] = CumSum[i-1] + A[i-1];
    }
    ll ans = 0;
    rep(i,N-K + 1){
        ans = max(ans,CumSum[i+K] - CumSum[i]);
    }
    cout << ans << endl;
}