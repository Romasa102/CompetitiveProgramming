#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin>>N;
    ll A[N];
    ll B[N];
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>B[i];
    sort(A,A+N);
    sort(B,B+N);
    ll ans = 0;
    rep(i,N){
        ans += abs(B[i]-A[i]);
    }
    cout << ans << endl;
}