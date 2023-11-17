#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    ll ans = 0;
    cin  >> N;
    rep(i,N){
        ll D;
        cin >> D;
        if((i+1)%11==0||i<9){
            if(D>=11*((i+1)%10)){
                ans+=2;
            }else if(D>=(i+1)){
                ans++;
            }
        }
    }
    cout << ans << endl;
}