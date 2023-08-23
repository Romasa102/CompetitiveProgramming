#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    vector<ll> Nums;
    ll o = 1;
    Nums[0] = 1;
    while(true){
        if(Nums[o-1] + o + 1 >1000000){
            break;
        }
        Nums.push_back(Nums[o-1] + o + 1);
        o++;
    }
    vector<ll> FNum;
    o = 1;
    while(true) {
        if (FNum[o - 1] + Nums[o - 1] > 1000000) {
            break;
        }
        FNum.push_back(FNum[o - 1] + Nums[o - 1])
        o++;
    }
    while(true){
        ll N;
        cin >> N;
        if(N == 0){
            return 0;
        }
        ll dp[1000000][FNum.size()];
        repp(i,1,N + 1){
            rep(j,FNum.size()){
                if(j-FNum[i-1] < 0){
                    dp[i][j] = dp[i-1][j];
                }
                dp[i][j] = max(dp[i-1][j-FNum[i-1]],dp[i-1][j]);
            }
        }
        rep(i,N+1){
            rep(j,){

            }
        }
    }
}