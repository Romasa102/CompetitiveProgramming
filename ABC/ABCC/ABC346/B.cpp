#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll W,B;
    cin >> W >> B;
    string S;
    rep(i,20)S+="wbwbwwbwbwbw";
    rep(i,S.size()){
        if(i+W+B>S.size())break;
        ll wc=0;ll bc=0;
        rep(j,W+B){
            if(S[i+j]=='w'){
                wc++;
            }else if(S[i+j]=='b'){
                bc++;
            }
        }
        if(wc==W&&bc==B){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}