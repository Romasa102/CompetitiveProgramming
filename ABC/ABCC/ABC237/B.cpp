#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    ll A[H][W];
    ll B[W][H];
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }
    rep(i,W){
        rep(j,H){
            cout << A[j][i] << " ";
        }cout << endl;
    }
}