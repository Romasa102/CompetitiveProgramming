#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N;
    vector<ll> A(N-1), B(N-1), X(N-1), dp(N, 1e18);
    rep(i,N-1) cin >> A[i] >> B[i] >> X[i];
    priority_queue<P,vector<P>,greater<P>>pq;
    pq.push({0, 0});
    while(!pq.empty()){
        ll time = pq.top().first;
        ll i = pq.top().second;
        pq.pop();
        if(i == N-1)continue;
        if(dp[i] < time) continue;
        if(i+1 < N && dp[i+1] > time + A[i]){
            dp[i+1] = time + A[i];
            pq.push({dp[i+1], i+1});
        }
        if(X[i]-1 < N && dp[X[i]-1] > time + B[i]){
            dp[X[i]-1] = time + B[i];
            pq.push({dp[X[i]-1], X[i]-1});
        }
    }
    cout << dp[N-1] << endl;
}