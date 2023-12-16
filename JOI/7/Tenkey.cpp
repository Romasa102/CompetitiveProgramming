#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll M,R;
    cin >> M >> R;
    ll dp[M][40][10];
    map<P,ll> dist;
    dist[{0,0}]=1;dist[{0,1}]=2;dist[{0,2}]=3;dist[{0,3}]=4;dist[{0,4}]=3;dist[{0,5}]=4;dist[{0,6}]=5;dist[{0,7}]=4;dist[{0,8}]=5;dist[{0,9}]=6;
    dist[{1,1}]=1;dist[{1,2}]=2;dist[{1,3}]=3;dist[{1,4}]=2;dist[{1,5}]=3;dist[{1,6}]=4;dist[{1,7}]=3;dist[{1,8}]=4;dist[{1,9}]=5;
    dist[{2,2}]=1;dist[{2,3}]=2;dist[{2,4}]=3;dist[{2,5}]=2;dist[{2,6}]=3;dist[{2,7}]=4;dist[{2,8}]=3;dist[{2,9}]=4;
    dist[{3,3}]=1;dist[{3,4}]=4;dist[{3,5}]=3;dist[{3,6}]=2;dist[{3,7}]=5;dist[{3,8}]=4;dist[{3,9}]=3;
    dist[{4,4}]=1;dist[{4,5}]=2;dist[{4,6}]=3;dist[{4,7}]=2;dist[{4,8}]=3;dist[{4,9}]=4;
    dist[{5,5}]=1;dist[{5,6}]=2;dist[{5,7}]=3;dist[{5,8}]=2;dist[{5,9}]=3;
    dist[{6,6}]=1;dist[{6,7}]=4;dist[{6,8}]=3;dist[{6,9}]=2;
    dist[{7,7}]=1;dist[{7,8}]=2;dist[{7,9}]=3;
    dist[{8,8}]=1;dist[{8,9}]=2;
    dist[{9,9}]=1;
    rep(i,M){
        rep(j,40){
            rep(k,10){
                dp[i][j][k]=1LL<<60;
            }
        }
    }
    rep(i,10){
        dp[0][0][i]=0;
    }
    ll modB = 1;
    ll num=1;
    rep(i,15){
        if(i!=0){
            num = (modB*10)%M;
            modB = num;
        }
        rep(j,M){
            rep(k,10){//place to start
                rep(l,10){// place to go
                    dp[(j+num*l)%M][i+1][l]=min(dp[(j+num*l)%M][i+1][l],dp[j][i][k]+dist[{min(k,l),max(k,l)}]);
                }
            }
        }
    }
    ll ans = 1LL<<60;
    rep(j,15){
        repp(k,1,10){
            ans = min(ans,dp[R][j][k]+dist[{0,k}]-1);
        }
    }
    cout << ans << endl;
}