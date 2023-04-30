#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,X;
    cin >> N >> X;
    P A[N];
    vector<ll> C(N);
    ll sumForNow = 0;
    rep(i,N){
        cin >> A[i].first >> A[i].second;
        sumForNow += min(A[i].first,A[i].second);
        C[i] = abs(A[i].first - A[i].second);
    }
    X -= sumForNow;
    vector<vector<bool>> dp(N + 1, vector<bool>(X + 1, false));
    for (int i = 0; i <= N; i++) {
        dp[i][0] = true;
    }
    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= X; k++) {
            if (k - C[i] >= 0) dp[i + 1][k] = dp[i + 1][k] | dp[i][k - C[i]];
            dp[i + 1][k] = dp[i + 1][k] | dp[i][k];
        }
    }
    if (dp[N][X]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}