#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll cityP[M];
    map<ll,ll> Change;
    rep(i,M){
        cin >> cityP[i];
    }
    rep(i,M-1){
        ll a = cityP[i];
        ll b = cityP[i+1];
        if(a > b)swap(a,b);
        Change[a-1]++;
        Change[b-1]--;
    }
    ll a[N-1];
    ll b[N-1];
    ll c[N-1];
    rep(i,N-1){
        cin >> a[i] >> b[i] >> c[i];
    }
    ll current = 0;
    ll ans = 0;
    rep(i,N-1){
        if(Change.find(i) != Change.end()){
            current+=Change[i];
        }
        if(c[i] + current * b[i] > a[i] * current){
            ans += a[i] * current;
        }else{
            ans += c[i] + current * b[i];
        }
    }
    cout << ans << endl;
}