#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll MOD = 1LL<<64 - 1;
    ll ans = 0;
    ll base = rng() % (MOD - 100) + 50;
    unordered_map<ll,ll> mp; // first index it appear.
    mp.reserve(N);
    repp(i,1,N+1){//length of search.
        ll cur = 0;
        mp.clear();
        ll bigN = 1;
        rep(j,i-1){
            bigN*=base;
            bigN%=MOD;
        }
        rep(j,i){
            cur *= base;
            cur %=MOD;
            cur+= (S[j]-'a');
            cur%=MOD;
        }
        mp[cur]=i-1;
        repp(j,i,N){
            cur += MOD;
            cur -= ((S[j-i]-'a') * bigN)%MOD;
            cur *= base;
            cur %= MOD;
            cur += (S[j]-'a');
            cur %= MOD;
            if(mp.find(cur)!=mp.end()){ // if it have appeared before.
                if(j - mp[cur] >= i){
                    ans = i;
                    break;
                }
            }else{
                mp[cur]=j;
            }
        }
    }
    cout << ans << endl;
}