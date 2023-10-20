#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    ll A[H][W];
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }
    vector<ll> horizontal(H);
    vector<ll> vertical(W);
    rep(i,H){
        ll sum = 0;
        rep(j,W){
            sum+=A[i][j];
        }
        horizontal[i]=sum;
    }
    rep(i,W){
        ll sum = 0;
        rep(j,H){
            sum+=A[j][i];
        }
        vertical[i] = sum;
    }
    rep(i,H){
        rep(j,W){
            cout << horizontal[i] + vertical[j] - A[i][j] << " ";
        }cout << endl;
    }
}