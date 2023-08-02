#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,o,n) for(ll i = o; i <= (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll ans = 0;
    rep(i,1,N){
        if((i&1)==0)continue;
        ll counter = 0;
        rep(j,1,i){
            if(i%j==0)counter++;
        }
        if(counter == 8){
            ans++;
        }
    }
    cout << ans << endl;
}