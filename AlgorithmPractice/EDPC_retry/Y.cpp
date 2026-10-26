#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll mod = 1e9+7;
const ll LIM = 200000;
ll* inv = new ll[LIM] - 1; 
ll fact[LIM], ifact[LIM];

ll dist(ll rDist, ll cDist){
    return 
        fact[rDist+cDist] * 
        ifact[rDist] % mod * 
        ifact[cDist] % mod;
}
int main(){
    inv[1] = 1;
    repp(i,2,LIM) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    fact[0] = ifact[0] = 1;
    repp(i,1,LIM){
        fact[i]  = fact[i-1]  * i      % mod;
        ifact[i] = ifact[i-1] * inv[i] % mod;
    }
    ll H,W,N;
    cin >> H >> W >> N;
    ll r[N],c[N];
    rep(i,N)cin >> r[i] >> c[i];
    vector<tuple<ll,ll,ll>> pt;
    rep(i,N){
        pt.push_back({r[i]+c[i],r[i],c[i]});
    }
    sort(pt.begin(),pt.end());
    vector<ll> dp(N); // first stopped at i-th
    rep(i,N){
        dp[i] = dist(get<1>(pt[i])-1,get<2>(pt[i])-1);
        dp[i] %= mod;
        rep(j,i){
            if((get<1>(pt[i]) - get<1>(pt[j]))>= 0 && (get<2>(pt[i]) - get<2>(pt[j]))>=0){
                dp[i] += mod;
                dp[i] -=( (dp[j] % mod) * (dist((get<1>(pt[i]) - get<1>(pt[j])),( get<2>(pt[i]) - get<2>(pt[j]))) % mod) )%mod;
                dp[i] %= mod;
            }
        }
    }
    ll Sans = 0;
    rep(i,N){
        //cout << i << "th point first route is : " << dp[i] << endl;
        Sans +=( dp[i]%mod) * (dist(H - get<1>(pt[i]) , W - get<2>(pt[i]))%mod);
        Sans%=mod;
    }
    cout << (dist(W-1,H-1) + mod - Sans) % mod << endl;
}