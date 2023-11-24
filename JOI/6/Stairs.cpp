#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,Pn;
    cin >> n >> Pn;
    ll h[n];
    vector<ll> cumS(n+1);
    cumS[0] = 0;
    rep(i,n)cin>>h[i];
    repp(i,1,n+1){
        cumS[i]=cumS[i-1]+h[i-1];
    }
    vector<ll> dp(n+1);
    vector<ll> changeN(n+10);
    rep(i,n+10)changeN[i]=0;
    ll cur = 0;
    dp[0]=1;
    rep(i,n+1){
        cur+=changeN[i];
        dp[i]=cur;
        if(i==0)dp[i]=1;
        if(lower_bound(cumS.begin(),cumS.end(),cumS[i]+Pn)!=cumS.end()){
            ll howL = lower_bound(cumS.begin(),cumS.end(),cumS[i]+Pn)-cumS.begin();
            changeN[i+1]+=dp[i];
            changeN[howL]-=dp[i];
        }else{
            changeN[i+1]+=dp[i];
        }
    }
    cout << dp[n] << endl;
}