#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    ll A,B,C;
    cin >> N >> A >> B >> C;
    ll ans = 1LL<<32;
    rep(i,9999){
        rep(j,9999){
            if((N-A*i-B*j)<0){
                continue;
            }
            if((N-A*i-B*j)%C==0){
                ans = min(i+j+(N-A*i-B*j)/C,ans);
            }
        }
    }
    cout << ans << endl;

}