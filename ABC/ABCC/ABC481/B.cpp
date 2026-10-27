#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll A[N];
    rep(i,N)cin >> A[i];
    ll ans = 0;
    rep(i,N){
        if(A[i]==K)ans++;
    }
    rep(i,N-1){
        if(A[i] < K && A[i+1] > K){
            ans++;
        }else if(A[i] > K && A[i+1] < K){
            ans++;
        }
    }cout << ans << endl;
}