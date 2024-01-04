#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}
int main(){
    ll N;cin >> N;
    ll A[N];rep(i,N)cin >> A[i];
    ll fromT[N];fromT[0]=A[0];
    ll fromB[N];fromB[N-1]=A[N-1];
    repp(i,1,N){
        fromT[i]=gcd(fromT[i-1],A[i]);
    }
    for(ll i = N-2; i >= 0; i--){
        fromB[i]=gcd(fromB[i+1],A[i]);
    }
    ll ans = max(fromT[N-2],fromB[1]);
    rep(i,N-2){
        ans = max(ans,gcd(fromT[i],fromB[i+2]));
    }
    cout << ans << endl;
}