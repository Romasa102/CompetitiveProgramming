#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll dp[1<<14][14];
ll N;
ll A[20][20];
ll rec(ll bit,int v){
    if(dp[bit][v] != -1)return dp[bit][v];//if visited return
    if(bit == 1<<0 && v == 0)return dp[bit][v] = 0; // in this case u must start from 0 so only set o to city 0
    if(bit == 1<<v)return dp[bit][v] = 1000000000;
    int prev_bit = bit & ~(1<<v);//the group u visited - {v}
    ll res = 10000000000;
    rep(i,N){
        if(1<<i & prev_bit){
            res = min(res,rec(prev_bit,i) + A[i][v]);
        }
    }
    return dp[bit][v] = res;
}
int main(){
    cin >> N;
    rep(i,N){
        rep(j,N){
            cin >> A[i][j];
        }
    }
    rep(i,1<<N){
        rep(j,N){
            dp[i][j] = -1;
        }
    }
    ll res = 10000000000;
    rep(i,N){
        res =  min(res,rec((1<<N)-1,i) + A[i][0]);
    }
    cout << res << endl;
}