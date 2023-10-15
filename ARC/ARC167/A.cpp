#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll A[N];
    rep(i,N)cin >> A[i];
    sort(A,A+N,greater<ll>());
    ll ans = 0;
    rep(i,2*M-N){
        ans += A[i]*A[i];
    }
    repp(i,2*M-N,M){
        ans+= (A[i]+A[N-1+(2*M-N)-i])*(A[i]+A[N-1+(2*M-N)-i]);
    }
    cout << ans << endl;
}