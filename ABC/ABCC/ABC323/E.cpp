#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}
int main(){
    ll N,X;
    cin >> N >> X;
    ll T[N];
    ll dp[X+10000];
    rep(i,X+10000){
        dp[i] = 0;
    }
    rep(i,N){
        cin >> T[i];
        dp[T[i]]++;
    }
    rep(i,X){
        rep(j,N){
            if(i+T[j] <= X){
                dp[i+T[j]]+=dp[i];
            }
        }
    }
    ll ans = 0;
    rep(i,T[0]+9999){
        ans += dp[X+9999-i];
    }
    cout << ans * modinv(,998244353) << endl;
}