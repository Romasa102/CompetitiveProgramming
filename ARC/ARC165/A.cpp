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
int main(){
    ll T;
    cin >> T;
    rep(i,T){
        ll N;
        cin >> N;
        vector<P> prime = prime_factorize(N);
        ll ans = 0;
        rep(j,prime.size()){
            ans += pow(prime[j].first,prime[j].second);
            cout << prime[j].first << " " << prime[j].second << endl;
        }
        cout << N << " " << ans << endl;
        if(ans >= N){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
}