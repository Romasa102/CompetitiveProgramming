#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll prime_factorize(ll N) {
    //time complexity is O(sqrt(N))
    ll res = 1;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;

        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        if(ex%2!=0){
            res*=a;
        }
    }
    if (N != 1) res*=N;
    return res;
}
int main(){
    ll N;cin >> N;
    vector<ll> A(N);
    map<ll,vector<ll>> mp;
    ll Zcount = 0;
    rep(i,N){
        cin >> A[i];
        if(A[i] == 0){
            Zcount++;
            continue;
        }
        mp[prime_factorize(A[i])].push_back(i);
    }
    ll ans = 0;
    if(Zcount != 0){
        ans += Zcount * (Zcount-1) / 2;
        ans += (N-Zcount) * Zcount;
    }
    for(auto i = mp.begin();i != mp.end();i++){
        if(i->second.size() == 1)continue;
        ans += i->second.size() * (i->second.size() - 1) / 2;
    }
    cout << ans << endl;
}