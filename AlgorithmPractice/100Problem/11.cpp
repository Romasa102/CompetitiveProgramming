#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll k;
    ll p[M];
    ll Switches[M];
    rep(i,M){
        cin >> k;
        Switches[i] = 0;
        rep(j,k){
            ll o;
            cin >> o;
            Switches[i] += 1<<(o-1);
        }
    }
    rep(i,M){
        cin >> p[i];
    }
    ll ans = 0;
    for(int bit = 0;bit < 1<<N; bit++){
        bool allL = true;
        for(int i = 0; i < M; i++){
            if(__builtin_popcount(Switches[i] & bit)%2 != p[i]){
                allL = false;
                break;
            }
        }
        if(allL)ans++;
    }
    cout << ans << endl;
}