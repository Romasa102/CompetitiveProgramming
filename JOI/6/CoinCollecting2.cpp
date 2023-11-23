#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    string S[H];
    rep(i,H)cin >> S[i];
    ll horizontS[H];//Aoi's
    vector<ll> verticalS(W);//Aoi's
    ll total = H*W;//Aoi's
    rep(i,H){
        ll cur =0;
        rep(j,W){
            if(S[i][j]=='#'){
                cur++;
            }
        }
        horizontS[i]=cur;
    }
    rep(i,W){
        ll cur =0;
        rep(j,H){
            if(S[j][i]=='#'){
                cur++;
            }
        }
        verticalS[i]=cur;
    }
    ll maxA = 0;
    vector<ll> cash;
    rep(i,H){
        cash = verticalS;
        //let's assume that Aoi select the line i and flipped it.
        rep(j,W){
            if(S[i][j]=='#'){
                cash[j]--;
            }else{
                cash[j]++;
            }
        }
        ll maxV = 0;
        ll minIndex=0;
        rep(j,W){
            if(cash[j]>maxV) {
                maxV=cash[j];
                minIndex=j;
            }
        }
        ll totalC = 0;
        cash[minIndex] = H-cash[minIndex];
        rep(j,W){
            totalC+=cash[j];
        }
        maxA = max(maxA,totalC);
    }
    cout << maxA << " " << total-maxA << endl;
}