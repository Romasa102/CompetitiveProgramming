#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<P> prime_factorize(ll N) {
    vector<P> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;

        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}
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
ll get_ans(ll A,ll B){
    vector<P> factorization = prime_factorize(A);
    ll ans = B;
    rep(i,factorization.size()){
        ans%=998244353;
        ans *= (factorization[i].second * B + 1)%998244353;
    }
    if(B%2==1 && (ll)sqrt(A) * (ll)sqrt(A)==A){
        ans--;
    }
    ans%=998244353;
    return (ans* 499122177)%998244353;
}
int main(){
    ll A,B;
    cin >> A >> B;
    B%=998244353;
    ll ans = get_ans(A,B);
    cout << (ll)ans << endl;
}