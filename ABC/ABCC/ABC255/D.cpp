#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    vector<ll> dp(N);
    sort(A.begin(),A.end(),greater<ll>());
    dp[0] = A[0];
    rep(i,N-1){
        dp[i+1] = dp[i] + A[i+1];
    }
    ll Mission;
    rep(i,Q){
        cin >> Mission;
        int a = lower_bound(A.begin(),A.end(),Mission)- A.begin();
        cout << dp[a - 1] - Mission*a + (Mission * (N - a) - (dp[N-1] - dp[a - 1])) << endl;
    }

}