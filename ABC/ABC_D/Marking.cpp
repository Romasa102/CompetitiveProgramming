#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(i,T){
        ll N,D,K;
        cin >> N >> D >> K;
        --K;
        int a = N / __gcd(N, D);
        cout << D * K % N + K / a << '\n';
    }
}