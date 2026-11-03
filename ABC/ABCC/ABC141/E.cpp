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
    ll base = 30;
    ll MOD = 1000000009;
    ll MOD2 = 998244353;
    ll ans = 0;
    unordered_map<ll,ll> mp; // first index it appear.
    mp.reserve(N);
    unordered_map<ll,ll> mp2; // first index it appear.
    mp2.reserve(N);
    repp(i,1,N+1){//length of search.
        ll cur = 0;
        ll cur2 = 0;
        mp.clear();
        mp2.clear();
        ll bigN = 1;
        ll bigN2 = 1;
        rep(j,i-1){
            bigN*=base;
            bigN%=MOD;
            bigN2*=base;
            bigN2%=MOD2;
        }
        rep(j,i){
            cur *= base;
            cur %=MOD;
            cur+= (S[j]-'a');
            cur%=MOD;


            cur2 *= base;
            cur2 %=MOD2;
            cur2+= (S[j]-'a');
            cur2%=MOD2;
        }
        mp[cur]=i-1;
        mp2[cur2]=i-1;
        repp(j,i,N){
            cur += MOD;
            cur -= ((S[j-i]-'a') * bigN)%MOD;
            cur *= base;
            cur %= MOD;
            cur += (S[j]-'a');
            cur %= MOD;


            cur2 += MOD2;
            cur2 -= ((S[j-i]-'a') * bigN2)%MOD2;
            cur2 *= base;
            cur2 %= MOD2;
            cur2 += (S[j]-'a');
            cur2 %= MOD2;
            if(mp.find(cur)!=mp.end() && mp2.find(cur2)!=mp2.end()){ // if it have appeared before.
                if(j - mp[cur] >= i && j-mp2[cur2] >= i){
                    ans = i;
                    break;
                }
            }else{
                mp[cur]=j;
                mp2[cur2]=j;
            }
        }
    }

    cout << ans<< endl;
}