#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

ll N;
vector<ll> dp;
vector<vector<ll>> a;
const ll MIN = -(1LL<<30);
ll divide(ll s){
    if(dp[s]!=MIN)return dp[s];
    //cout << "checking for" << s << endl;
    vector<ll> inc;
    rep(i,N){
        if(s & 1<<i){ // means that it include ith num
            inc.push_back(i);
            //cout<< "pushed " << i << endl;
        }
    }
    ll cur = 0;
    if(inc.size()!=1){
        rep(i,inc.size()-1){
            repp(j,i+1,inc.size()){
                cur += a[inc[i]][inc[j]];
                //cout << "adding between " << inc[i] << " " << inc[j] << " " << cur << endl;
            }
        }
    }
    for(ll t = s; t >= 0; t--){
        t&=s;
        if(t==s || t==0)continue;
        //cout << "for " << s << " divided into " << t <<"  " << s-t << endl;;
        cur = max(cur, divide(t) + divide(s-t));
    }
    //cout << "max score with group " << s << " was " << cur << endl;
    return dp[s]=cur;
}
int main(){
    cin >> N;
    a.resize(N,vector<ll>(N,0));
    rep(i,N)rep(j,N)cin >>a[i][j];
    dp.resize(1<<(N+1),MIN);
    ll ans = divide((1<<(N))-1);
    cout << ans << endl;
}