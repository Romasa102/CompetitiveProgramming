#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S[5];
    rep(i,5)cin >> S[i];
    ll maxCnt = 0;
    rep(i,5){
        ll cnt = 0;
        rep(j,5){
            if(S[i][j]=='o')cnt++;
        }
        maxCnt=max(maxCnt,cnt);
    }
    rep(j,5){
        ll cnt = 0;
        rep(i,5){
            if(S[i][j]=='o')cnt++;
        }
        maxCnt=max(maxCnt,cnt);
    }
    ll cnt = 0;
    rep(i,5){
        if(S[i][i]=='o'){
            cnt++;
        }
    }
    maxCnt = max(maxCnt,cnt);
    cnt = 0;
    rep(i,5){
        if(S[4-i][i]=='o'){
            cnt++;
        }
    }
    maxCnt = max(maxCnt,cnt);
    cout << 5 - maxCnt << endl;
}