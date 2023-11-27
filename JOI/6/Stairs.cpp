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
    vector<ll> dp(n+1,0);
    vector<ll> changeN(n+10,0);
    ll cur = 0;
    rep(i,n+1){
        cur+=changeN[i];
        cur%=1234567;
        dp[i]=cur;
        dp[i]%=1234567;
        if(i==0)dp[i]=1;
        if(cumS[i]+Pn < cumS[i+1])continue;
        if(upper_bound(cumS.begin(),cumS.end(),cumS[i]+Pn)==cumS.end()){
            changeN[i+1]+=dp[i];
            changeN[i+1]%=1234567;
        }else{
            ll howL = upper_bound(cumS.begin(),cumS.end(),cumS[i]+Pn)-cumS.begin();
            changeN[i+1]+=dp[i];
            changeN[i+1]%=1234567;
            changeN[howL]-=dp[i];
            changeN[howL]%=1234567;
        }
    }
    if(dp[n]<0){
        cout << dp[n] + 1234567 << endl;
    }else{
        cout << dp[n] << endl;
    }
}