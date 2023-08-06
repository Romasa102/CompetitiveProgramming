#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N){
        cin >> A[i];
    }
    ll B[N];
    rep(i,N){
        cin >> B[i];
    }
    ll C[N];
    rep(i,N) {
        cin >> C[i];
    }
    sort(A,A+N);
    sort(B,B+N);
    sort(C,C+N);
    ll ans = 0;
    rep(i,N){
        ll a = lower_bound(A,A+N,B[i]) - A;
        ll c = N - (upper_bound(C,C+N,B[i]) - C);
        ans += a * c;
    }
    cout << ans << endl;
}