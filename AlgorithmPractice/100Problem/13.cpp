#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll R,C;
    cin >> R >> C; //R is smaller than 10
    bool Senbei[R][C];
    rep(i,R){
        rep(j,C){
            int p;
            cin >> p;
            Senbei[i][j] = p;
        }
    }
    ll ans = 0;
    for(int bit = 0; bit < 1 << R; bit++){
        ll now = 0;
        bool cashSenbei[R][C];
        for(int i = 0; i < R; i++){
            if(bit & 1<<i){
                rep(j,C){
                    cashSenbei[i][j] = !Senbei[i][j];
                }
            }else{
                rep(j,C){
                    cashSenbei[i][j] = Senbei[i][j];
                }
            }
        }
        rep(i,C){
            ll counter = 0;
            rep(j,R){
                if(cashSenbei[j][i]){
                    counter++;
                }
            }
            if(counter < R-counter){
                now += R-counter;
            }else{
                now += counter;
            }
        }
        ans = max(ans,now);
    }
    cout << ans << endl;
}