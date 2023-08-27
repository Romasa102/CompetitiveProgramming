#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    ll length[10][10];
    rep(i,10){
        rep(j,10){
            cin >> length[i][j];
        }
    }
    rep(k,10){
        rep(i,10){
            rep(j,10){
                if(length[i][j] > length[i][k] + length[k][j]){
                    length[i][j] = length[i][k] + length[k][j];
                }
            }
        }
    }
    ll A[H][W];
    ll ans = 0;

    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
            if(A[i][j] != -1){
                ans += length[A[i][j]][1];
            }
        }
    }
    cout << ans << endl;
}