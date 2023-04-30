#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll H,W,R,C;
    cin >> H >> W >> R >> C;
    ll ans = 4;
    if(R - 1 == 0){
        ans--;
    }
    if(R + 1 > H){
        ans--;
    }
    if(C - 1 == 0){
        ans--;
    }
    if(C + 1 > W){
        ans--;
    }
    cout << ans << endl;
}