#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    vector<ll> Nums;
    ll o = 1;
    Nums.push_back(1);
    while(true){
        if(Nums[o-1] + o + 1 >1000000){
            break;
        }
        Nums.push_back(Nums[o-1] + o + 1);
        o++;
    }
    vector<ll> FNum;
    FNum.push_back(1);
    o = 1;
    while(true) {
        if (FNum[o - 1] + Nums[o] > 1000000) {
            break;
        }
        FNum.push_back(FNum[o - 1] + Nums[o]);
        o++;
    }
    ll MAX = 1000000;
    ll dp[MAX+1];
    rep(i,MAX+1){
        dp[i] = 1000;
    }
    dp[0] = 0;
    repp(i,0,MAX+1){
        rep(j,FNum.size()){
            if(i + FNum[j] > MAX){
                break;
            }
            dp[i+FNum[j]] = min(dp[i+FNum[j]],dp[i] + 1);
        }
    }
    ll dpO[MAX+1];
    rep(i,MAX+1){
        dpO[i] = 1000;
    }
    dpO[0] = 0;
    repp(i,0,MAX+1){
        rep(j,FNum.size()){
            if(FNum[j]%2 == 0)continue;
            if(i + FNum[j] > MAX){
                break;
            }
            dpO[i+FNum[j]] = min(dpO[i+FNum[j]],dpO[i] + 1);
        }
    }
    while(true){
        ll N;
        cin >> N;
        if(N == 0){
            break;
        }
        cout << dp[N] << " " <<  dpO[N] << endl;
    }
}