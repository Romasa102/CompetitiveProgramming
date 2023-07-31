#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll h[N];
    ll dp[N];
    rep(i,N){
        dp[i] = 0;
        cin >> h[i];
    }
    for(ll i = 1;i<N;i++){
        ll smallest = 1000000;
	    dp[i]=dp[i-1]+abs(h[i-1]-h[i]);
        for(ll j = 1;j < K+1; j++){
            if(i-j>=0)dp[i] = min(dp[i],dp[i-j]+abs(h[i-j]-h[i]));
        }
    }
    cout << dp[N-1] << endl;
}