#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    P A[N+1];
    rep(i,N+1) {
        cin >> A[i].first;
        A[i].second = i;
    }
    ll B[N];
    rep(i,N)cin >> B[i];
    sort(A,A+N+1);
    sort(B,B+N);
    ll left[N+1];
    ll right[N+1];
    left[0] = 0;
    right[N] = 0;
    right[N-1] = max(0LL,A[N].first-B[N-1]);
    rep(i,N){
        left[i+1] = max(max(0LL,A[i].first-B[i]),left[i]);
    }
    for(ll i = N-1;i>=0;i--){
        right[i] = max(right[i+1],max(0LL,A[i+1].first-B[i]));
    }
    map<ll,ll> ans;
    rep(i,N+1){
        ans[A[i].second] = max(left[i],right[i]);
    }
    rep(i,N+1){
        cout << ans[i] << " ";
    }cout << endl;
}