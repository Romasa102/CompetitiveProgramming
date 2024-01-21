#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W,K;
    cin >> H >> W >> K;
    string S[H];
    rep(i,H)cin >> S[i];
    ll ans = -1;
    rep(i,H){
        ll openSpace = 0;
        ll maxF = 0;
        ll filled = 0;
        rep(j,W){
            if(S[i][j] != 'x')openSpace++;
            if(S[i][j] == 'x'){
                openSpace = 0;
                maxF = 0;
                filled = 0;
                continue;
            }
            if(S[i][j] == 'o')filled++;
            if(openSpace > K){
                if(S[i][j-K] == 'o'){
                    filled--;
                }
            }
            maxF = max(filled,maxF);
            if(openSpace >= K){
                ans = max(ans,maxF);
            }
        }
    }
    rep(j,W){
        ll openSpace = 0;
        ll maxF = 0;
        ll filled = 0;
        rep(i,H){
            if(S[i][j] != 'x')openSpace++;
            if(S[i][j] == 'x'){
                openSpace = 0;
                maxF = 0;
                filled = 0;
                continue;
            }
            if(S[i][j] == 'o')filled++;
            if(openSpace > K){
                if(S[i-K][j] == 'o'){
                    filled--;
                }
            }
            maxF = max(filled,maxF);
            if(openSpace >= K){
                ans = max(ans,maxF);
            }
        }
    }
    if(ans == -1){
        cout << "-1" << endl;
        return 0;
    }
    cout << K - ans << endl;
}