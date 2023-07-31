#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    string I;
    int M[H][W];
    rep(i,H){
        cin >> I;
        rep(j,W){
            if(I[j] == '.'){
                M[i][j] = 0;
            }else if(I[j] == '#'){
                M[i][j] = 1;
            }
        }
    }
    
}