#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int modPow(long long a, long long n, long long p) {
    if (n == 0) return 1; // 0乗にも対応する場合
    if (n == 1) return a % p;
    if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
    long long t = modPow(a, n / 2, p);
    return (t * t) % p;
}
int main(){
    ll p,n;
    cin >> p >> n;
    ll reminder[p];
    rep(j,p){
        reminder[j]=modPow(j,n,p);
    }
    ll remC[p];
    rep(i,p)remC[i]=0;
    rep(i,p){
        //cout << reminder[i] << endl;
        remC[reminder[i]]++;
    }
    ll ans = 0;
    rep(i,p){
        rep(j,p){
            ans += remC[i]*remC[j]*remC[(i+j)%p];
        }
    }
    cout << ans << endl;
}