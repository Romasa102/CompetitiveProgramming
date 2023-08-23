#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,X;
    cin >>  N >> X;
    ll x[N];
    rep(i,N){
        cin >> x[i];
    }
    vector<ll> GCDRef;
    rep(i,N){
        GCDRef.push_back(x[i] - X);
    }
    ll finalGCD = GCDRef[0];
    rep(i,N-1){
        finalGCD = __gcd(finalGCD,GCDRef[i+1]);
    }
    cout << abs(finalGCD) << endl;
}