#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("sleepy.in","r",stdin);freopen("sleepy.out","w",stdout);
    ll N;cin >> N;ll p[N];rep(i,N)cin>>p[i];
    ll ans = 0;
    rep(i,N-1){
        if(p[i]>p[i+1]){
            ans = i+1;
        }
    }
    cout << ans << endl;
}